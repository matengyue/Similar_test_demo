#!/usr/bin/env python
# coding=utf-8
import sys
import jieba

reload(sys)
sys.setdefaultencoding('utf-8')

file_object = open(sys.argv[1])
try:
    all_the_text = file_object.read()
finally:
    file_object.close()

seg_list = jieba.cut(all_the_text)
print "\n".join(seg_list)
