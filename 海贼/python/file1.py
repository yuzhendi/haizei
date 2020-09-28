#!/usr/bin/env python
# coding=utf-8
fo = open("./input","r+")
print("文件名：",fo.name)
fo.seek(0,2) #表示当前文件指针的结尾的位置(第2行)
fo.write("\nwww.haizeix.com")
fo.seek(0)
fo.close()
with open("./input","r") as fo:
    print(fo.read())
