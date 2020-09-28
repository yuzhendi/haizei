#!/usr/bin/env python
# coding=utf-8

# 使用requests 发送请求和携带参数

#导入模块
import requests

# 发送请求 （get）
url = "https://www.baidu.com"
'''
r = requests.get(url)
r.encoding = 'utf-8' # 规范格式
print (r.text)

# 发送请求和携带参数

print ("携带参数的\n")
r = requests.get(url, params = {'key1':'value1', 'key2':'value2'})
r.encoding = 'utf-8' # 规范格式
print (r.text)

# 发送post请求，并传递参数
'''
r = requests.post(url, data = {'key' : 'value'})
r.encoding = 'utf-8'
print (r.text)
