#!/usr/bin/env python
# coding=utf-8

# os 模块
import os
#打开文件
path = '/home/yuzhendi/海贼/python'
dirs = os.listdir(path) 
for file in dirs:
    print(file)

#创建多级目录
path = './test/a'
os.makedirs(path)
#判断路径是否存在
