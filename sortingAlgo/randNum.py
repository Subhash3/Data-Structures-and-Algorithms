#!/usr/bin/python3

import random

fhand = open("file.txt", 'w')
num = 1000
fhand.write(str(num)+' ')
for i in range(num) :
    fhand.write(str(random.randint(0, 1000))+' ')
