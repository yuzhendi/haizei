#!/usr/bin/env python
# coding=utf-8

import requests



# 获取图片链接返回一个列表
def get_url(response):    
    # 用jsondata保存 用json.loads的方法处理返回回来的类似字典的格式
    jsondata = json.loads(response.text)
    # 创建一个空的列表,用于处理提取出来的Url
    image_url = []
    # 检查字典里是否包含data这个关键字
    if 'data' in jsondata.keys():
        # 从字典里面提取出data这个键的值
        for items in jsondata.get('data'):
            # 从items这个自动中提取thumbURL的值,返回一个url
            url = items.get('thumbURL')
            # 空列表添加提取出来的url
            image_url.append(url)
    # 添加完成后统一返回

# 下载用的函数
def downimage(image_url):
    # 从我们传入的url列表重依次取出url
    for url in image_url:
        # 异常处理
        try:
            # 请求我们图片地址得到返回
            response = requests.get(url)
            # 判断响应码
            if response.status_code == 200:
                # 用切片的方法给图片命名
                name = url.split(',')[-1].split('&')[0]
                # 以字节的方式读取读取数据
                image = response.content
                # 创建一个空白的文件,以二进制的方式写入数据
                # 给创建出来的这个文件取个别名叫f
                with open('./data/tieba/images/%s.jpg' % name, 'wb') as f:
                    # 写入我们的2进制数据
                    f.write(image)
        except:
            print('当前请求出错')

root_url = "https://movie.douban.com/top250" #根部链接
response = requests.get(root_url)
image_url = get_url(response)
downimage(image_url)

