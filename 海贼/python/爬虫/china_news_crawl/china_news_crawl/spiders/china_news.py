import scrapy
from bs4 import BeautifulSoup
from ..items import ChinanewsCrawlItem
class ChinanewsCrawlSpider(scrapy.Spider):
    name = 'chinanews'
    allowed_domains = ['chinanews.com']
    start_urls = ['http://chinanews.com/rss/scroll-news.xml']

    def parse(self, response):
        rss = BeautifulSoup(response.body, "html.parser")
        for item in rss.findall("item"):
            feed_item = ChinanewsCrawlItem() #返回一个对象
            feed_item['title'] = item.title.text # 后面的是页面代码中的内容
            feed_item['link'] = item.link.text
            feed_item['desc'] = item.description.text
            feed_item['pub_date'] = item.pubDate
            yield feed_item #迭代对象
