#!/usr/bin/env python
# coding=utf-8

class Student(object) :
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def show(self):
        print("%s : %d"% (self.name, self.age))  # 用 % 进行占位

stu1 = Student("jack", 12)
stu2 = Student("marry",13)

stu1.show()
stu2.show()
