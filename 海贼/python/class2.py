#!/usr/bin/env python
# coding=utf-8

#父类
class Animal(object):
    def __init__(self, name):
        self.name = name
    def run(self):
        print("{}run...".format(self.name))

#子类
class Cat(Animal):
    #重写父类的方法
    '''
    def __init__(self,name, color):
        #调用父类的方法
        #super().__init__(name)
        Animal.__init__(self,name)
        self.color = color
        '''
    def show(self):
        print("name={}".format(self.name))
cat = Cat("cat")
cat.show()
