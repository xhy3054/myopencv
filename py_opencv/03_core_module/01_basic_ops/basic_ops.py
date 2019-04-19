#!/usr/bin/env python
# encoding=utf-8

import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt

img = cv.imread('earth-16-bit-per-channel.png')
b,g,r = cv.split(img)
img = cv.merge((r,g,b))

plt.imshow(img)
plt.show()
