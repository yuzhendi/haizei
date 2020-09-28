#!/usr/bin/env python
# coding=utf-8

# urllib的使用
import urllib.request

#向一个指定的URL发送请求，获取回应

response = urllib.request.urlopen("http://www.haizeix.com")
#获取相应内容
content = response.read().decode('utf-8')
print (content)

fo = open('./haizei.html','w', encoding = 'utf-8')
print(content, file = fo)
fo.close()
#响应头信息
print(response.headers)
#相应码
print (response.status)
