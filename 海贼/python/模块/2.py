#!/usr/bin/env python
# coding=utf-8

# datetime 模块
from datetime import datetime  
#获取当前时间
now =datetime.now()
print (now)

#创建指定日期对象

date1 = datetime(2015, 7, 16,11, 50, 40)
print (date1)
#转时间戳
print (now.timestamp())
#日期转字符串
print(now.strftime('%Y-%m-%d'))
#字符串转日期
data2 = datetime.strptime('2020-7-16','%Y-%m-%d')
print (data2)


