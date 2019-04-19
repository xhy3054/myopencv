#!/usr/bin/env python
# encoding=utf-8
import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt

im = cv.imread("earth-16-bit-per-channel.png")
cv.imshow('cv.imshow', im)

#64位机器必须加上 &0xFF
k = cv.waitKey(0) & 0xFF
if k == 27:         # wait for ESC key to exit
    cv.destroyAllWindows()
elif k == ord('s'): # wait for 's' key to save and exit
    cv.imwrite('imwrite.jpg',im)
    cv.destroyAllWindows()


#因为cv读入图片存入numpy的二维数组中，所以可以直接使用plt显示
plt.imshow(im)
#由于opencv是bgr，matplotlib显示会出现一些问题
plt.xticks([]), plt.yticks([])  # to hide tick values on X and Y axis
plt.show()
