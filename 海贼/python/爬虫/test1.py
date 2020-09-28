#!/usr/bin/env python
# coding=utf-8
import re
import requests
import json
'''
def get_image_url(response):
    jsondata = json.loads(response.text)
    image_url = []
    if 'data' in jsondata.keys():
        for items in jsondata.get('data'):
            url = items.get('thumbURL')
            image_url.append(url)
'''
def downimage(image_url):
    for url in image_url:
        response = requests.get(url)
        pattern = "$.jpg"
        if re.match(pattern, url) != None:
            name = url.split(',')[-1].split('&')[0]
            image = response.content
            with open("./data/tieba/images/%s.jpg" % name, 'wb') as f:
                f.write(image)

root = "https://image.baidu.com/search/index?tn=baiduimage&ps=1&ct=201326592&lm=-1&cl=2&nc=1&ie=utf-8&word=%E8%B1%86%E7%93%A3%E7%94%B5%E5%BD%B1%E8%AF%84%E5%88%86%E6%8E%92%E8%A1%8C"
#root = "https://movie.douban.com/top250"
response = requests.get(root)
#response = requests.get(root, params = {'ie':'value1','kw':'value2','fn':'value3'})
pattern = re.compile('^http*$.jpg')
image_url = pattern.findall((str)(response.text))
#image_url = get_image_url(response)
downimage(image_url)
