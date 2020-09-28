#!/usr/bin/env python
# coding=utf-8

# 爬百度贴吧

import requests
import re

class TiebaSpider:
    # 贴吧爬虫
    def __init__(self):
        # 初始化参数
        self.kw = input("关键词：")
        self.base_url = "http://tieba.baidu.com/f" 
        self.page_num = 1
        self.title = ''
        # 更改响应头， 防止反爬
        self.headers = {"User-Agent" : "Mozilla/5.0(Macintosh;Intel Mac OS 10_9_2) AppleWebKit/537.75.14(KHTML, like Gecko) Version/7.0.3 Safari/537.75.14"}
    
    def parase_text(self, url, params = None):
        # 发送请求 获取响应内容
        sponse = requests.get(url) 
        return sponse.text# 响应文本信息
    
    def parase_byte(self, url, params = None):
        sponse = requests.get(url)
        return sponse.content#返回响应对象的content

    def save_title(self):
        # 保存帖子的标题
        print("保存帖子的标题")
    def save_image(self, url):
        #保存图片
        print("保存第{}页图片".format(self.page_num))
        pattern = re.compile('http*$.jpg')
        text = self.parase_text(url)
        image_url= pattern.findall(text) #返回一个列表
        for now_url in image_url:
            response = requests.get(now_url)
            name = url.split(',')[-1].split('&')[0]
            image = response.content
            with open("./data/tieba/images/%s.jpg" % name, "wb") as file:
                file.write(image)
                print("写入完毕")

    def page(self, line):
        # 解析每一页
        print("第{}页爬取中...".format(self.page_num))
        #save_title(self)
        self.save_image(self.base_url)
        #判断下一页
        if re.search('^herf*下一页*',line):
            #self.parase_text()
            self.save_title()
            self.save_image(self, self.base_url)
            #爬取下一页
        else : 
            print("爬虫完毕!一共爬取了{}页".format(self.page_num))

    def start(self):
        # 开始爬虫
        print("爬虫开始...")
        content = self.parase_text(url = self.base_url, params = {'kw' : self.kw, 'ie': 'utf-8', 'fr' : 'search'})
        self.page(content)

spider = TiebaSpider()
spider.start()
print("主函数开始")
'''
if __name__ == '__main':
    spider = TiebaSpider()
    spider.start()
    print("主函数开始:")
'''
