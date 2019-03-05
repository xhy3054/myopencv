# 相机标定

## 主要功能
1. 标定计算出畸变矩阵、内参矩阵
2. 从相机、视频或图片序列读取输入
3. 读取配置文件(XML/YAML)
4. 保存结果到(XML/YAML)
5. 计算重投影误差

## 透镜畸变
现代相机为了获得更好的成像效果，相机里一般都加入了透镜。而透镜的加入对成像过程中光线的传播会产生新的影响，进而出现畸变，一般有两种主要的畸变：

- **径向畸变**：透镜自身的形状对光线传播会有影响；
    - 桶形畸变：图像放大率随着与光轴之间的距离增加而减小
    - 枕形畸变：图像放大率随着与光轴之间的距离增大而增大

    一般径向畸变对于二维平面上一个坐标(x,y)（如上图畸变最小的点为坐标原点，一般在图像中心，r是点到原点的距离）的影响可以使用如下公式表述：

$$ x_{distorted} = x( 1 + k_1 r^2 + k_2 r^4 + k_3 r^6) \\ y_{distorted} = y( 1 + k_1 r^2 + k_2 r^4 + k_3 r^6) $$

> 无论是桶形畸变还是枕形畸变，由于他们都是随着与中心之间的距离增加而增加，因此可以使用一个**多项式函数**来描述畸变前后的像素坐标变化。这个公式中，对于畸变较小的图像中心区域，畸变主要是$k_1$在起作用；而对于畸变较大的边缘区域，主要是$k_2$在起作用。一般的普通摄像头用这两个系数就已经可以很好地纠正径向畸变了。但是对于一部分畸变很大的摄像头，比如说鱼眼镜头等，还需要加入$k_3$畸变项才能比较好的表述畸变情况。

- **切向畸变**：在机械组装过程中，透镜和成像平面不可能完全平行，这也会使得光线穿过透镜投影到成像面时的位置出现变化；

    一般切向畸变对于二维平面上的坐标(x,y)的影响可以使用如下公式进行表述：

$$ x_{distorted} = x + [ 2p_1xy + p_2(r^2+2x^2)] \\ y_{distorted} = y + [ p_1(r^2+ 2y^2)+ 2p_2xy] $$

### 加入畸变的成像(理想情况下)
- 首先，世界坐标系下有一个固定的点P，**世界坐标**是 $P_w$

- 获得点P的**相机坐标系坐标**，可以利用相机外参R与t得到 $ P_c = RP_w + t $

- 在2中获得的 $P_c$ 仍然是三维的 (X,Y,Z) ，将其投影到归一化平面 $Z=1$ 上，得到**归一化相机坐标**：$ P_C = [X/Z, Y/Z, 1]^T $

- 此处加入**畸变**因素，畸变公式如下(其中，$x=X/Z, y=Y/Z$)：

$$ x_{distorted} = x( 1 + k_1 r^2 + k_2 r^4 + k_3 r^6) + [ 2p_1xy + p_2(r^2+2x^2)] \\ y_{distorted} = y( 1 + k_1 r^2 + k_2 r^4 + k_3 r^6) + [ p_1(r^2+ 2y^2)+ 2p_2xy] $$

- 最后一步，利用内参K，将归一化相机坐标转换成**像素坐标**： $ P_{uv} = KP_{distorted} $

$$ u = f_x x_{distorted} + c_x \\ v = f_y y_{distorted} + c_y $$


> 此处之所以将畸变放在内参前面作用，是因为上面已经说过了这个畸变模型假设的原点是图像中心，也就是未经过内参作用时符合。

## 相机标定
现在，我们知道，将一个三维世界坐标点通过相机映射到像素平面上一般需要三个矩阵参数，分别是相机外参、相机内参、畸变参数。其中相机外参是固定不变的，并且可以由相机的位姿固定获得。而相机内参与畸变参数一般可以通过**相机标定**来获取。

> 需要说明的是相机标定只是对相机物理特性的**近似**获取。