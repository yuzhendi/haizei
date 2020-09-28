#!/usr/bin/env python
# coding=utf-8
import requests
src="http://tiebapic.baidu.com/forum/w%3D580/sign=674373497759252da3171d0c049a032c/3d3a84d7277f9e2fb9b28c5b0830e924b999f315.jpg"
response = requests.get(src)
with open('./data/tieba/images/1.jpg', 'wb') as file:
    file.write(response.content)
