import cv2 as cv
import numpy as np
import random
import pyflann

width = 500
height = 500
img = np.zeros((width, height, 3), dtype=np.uint8)

npoint = 1000
points = []
for i in range(npoint):
    points.append((random.randint(0,width), random.randint(0,height)))

for point in points:
    cv.circle(img, point, 1, (0,255,255), -1)

'''
    FLANN_INDEX_LINEAR = 0,
    FLANN_INDEX_KDTREE = 1,
    FLANN_INDEX_KMEANS = 2,
    FLANN_INDEX_COMPOSITE = 3,
    FLANN_INDEX_KDTREE_SINGLE = 4,
    FLANN_INDEX_HIERARCHICAL = 5,
    FLANN_INDEX_LSH = 6,
    FLANN_INDEX_SAVED = 254,
    FLANN_INDEX_AUTOTUNED = 255, 
'''
#params = dict(algorithm=1, trees=1)
params = dict(algorithm=2)
flann1 = cv.flann_Index(np.float32(points), params)
flann2 = flann.build_index(np.float32(points), algorithm = 'kdtree', trees=1)

k=20
search_mat = np.float32([width//2, height//2])
indices,dists = flann2.knnSearch(search_mat, k)
print('search_mat = ', search_mat)
print('indices = ', indices[0])
print('dists = ', dists[0])
img_show = img.copy()
for i in indices[0]:
    print(points[i])
    cv.circle(img_show, points[i], 1, (255,255,0), -1)
    cv.line(img_show, (width//2, height//2), points[i], (0,0,255))
cv.imshow("flann最近邻搜索结果展示图", img_show)
cv.waitKey(0)

