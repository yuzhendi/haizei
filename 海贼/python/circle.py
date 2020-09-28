#!/usr/bin/env python
# coding=utf-8

import math #引用包

'''
def circle(r):
    result = math.pi * r * r
    return result 
r = float(input("请输入圆的半径:"))
print("员的半径为:"+str(r)+"\n圆的面积是" + str(circle(r)))
'''
r = float(input("请输入圆的半径： "))
result = lambda r : math.pi * r * r
print ("result : ",result(r))
