#!/usr/bin/env python
# coding=utf-8
#多态

#父类
class Animal(object):
    def __init__(self, name):
        self.name = name
    def say(self):
        print("父类：{}".format(self.name))

#子类
class Cat(Animal):
    def say(self):
        print("子类（cat){}".format(self.name))

class Dog(Animal):
    def say(self):
        print("子类（Dog){}".format(self.name))
#动物叫的函数
def Animal_say(animal): #传入一个对象  ----多态性
    animal.say()

#传入Animal的实例
Animal_say(Animal('a'))
#传入dog的实例
Animal_say(Dog('b'))
#传入Cat
Animal_say(Cat('c'))

