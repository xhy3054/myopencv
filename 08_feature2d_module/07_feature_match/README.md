# 特征匹配
- 在opencv中特征匹配的类都是从`cv::DescriptorMatcher`基类中派生出来的。目前总共有两种，分别是`cv::BFMatcher`与`cv::FlannBasedMatcher`

- 在`cv::DescriptorMatcher`基类中总共有三种比较常见的匹配方法。
    - `match()`: 对于每个特征点的描述子找到最好的一个匹配
    - `knnMatch()`: 对于每个特征点的描述子找到与其最近的k个匹配
    - `radiusMatch()`: 对于每个特征点的描述子找到不超过指定距离的所有匹配


## 暴力匹配`cv::BFMatcher`
- 这种方法对于第一幅图像里的每个特征点的descriptor都会在图像二里遍历所有的descriptor，然后选取其中度量距离最近的作为匹配。

- 创建暴力匹配器时，有两个参数，
    - 一般只需要使用第一个参数，决定使用什么距离度量就可以了。
    - 如果需要也可以使用第二个参数（一个bool类型默认参数），决定是否启用交叉检查，默认不开启false。（所谓的交叉检查就是反过来使用被匹配到的点再进行一次匹配，如果匹配到的仍然是第一次匹配到的点对，就认为这是一次正确的匹配）
使用方法一般如下：
```cpp
BFMatcher matcher(NORM_HAMMING);
matcher.match(descriptor1, descriptor2, matches); //matches是存储匹配对的向量
```
---

## 快速近似最近邻搜索`cv::FlannBasedMatcher`
- 术语`FLANN`本是指用于近似近邻计算的快速库，这是一个对大数据集和高维特征进行最近邻搜索的算法的集合。opencv使用这个第三方库，因此这种匹配方式在面对大数据集时它的效果要好于`cv::BFMatcher`。这种方法特点是不一定找到的是最近的，所以叫近似最近邻，主要特点是快。

- 创建`cv::FlannBasedMatcher`时需要传入两个字典参数，有需要再看，可以直接使用默认参数

- 在使用这种匹配方法时，需要首先将描述子类型转换成32位浮点型

