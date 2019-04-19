import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt
img1 = cv.imread('../../data/1.png',0)          # queryImage
img2 = cv.imread('../../data/2.png',0) # trainImage
# Initiate SIFT detector
orb = cv.ORB_create(100)
# find the keypoints and descriptors with SIFT
kp1, des1 = orb.detectAndCompute(img1,None)
kp2, des2 = orb.detectAndCompute(img2,None)
# BFMatcher with default params
bf = cv.BFMatcher()
matches = bf.knnMatch(des1,des2, k=2)
# Apply ratio test
good = []
for m,n in matches:
    if m.distance < 0.75*n.distance:
        good.append([m])
# cv.drawMatchesKnn expects list of lists as matches.
img3 = np.empty((max(img1.shape[0], img2.shape[0]), img1.shape[1]+img2.shape[1], 3), dtype=np.uint8)
cv.drawMatchesKnn(img1,kp1,img2,kp2,good,img3, flags=2)
plt.imshow(img3),plt.show()
