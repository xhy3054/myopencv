# add a Trackbar
这个教程主要是演示一下如何在一个窗口添加`Trackbar`。

## 程序说明
这个程序作用是线性叠加两幅图像。使用`Trackbar`作为参数输入，动态监控输入，实时更新结果。

```cpp
int cv::createTrackbar  (   const String &  trackbarname,
const String &  winname,
int *   value,
int     count,
TrackbarCallback    onChange = 0,
void *  userdata = 0 
)   
/*
Parameters
trackbarname    Name of the created trackbar.
winname Name of the window that will be used as a parent of the created trackbar.
value   Optional pointer to an integer variable whose value reflects the position of the slider. Upon creation, the slider position is defined by this variable.
count   Maximal position of the slider. The minimal position is always 0.
onChange    Pointer to the function to be called every time the slider changes position. This function should be prototyped as void Foo(int,void*); , where the first parameter is the trackbar position and the second parameter is the user data (see the next parameter). If the callback is the NULL pointer, no callbacks are called, but only value is updated.
userdata    User data that is passed as is to the callback. It can be used to handle trackbar events without using global variables.
*/

```
