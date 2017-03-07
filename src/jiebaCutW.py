#!/usr/bin/env python
# coding=utf-8
import sys
import jieba

reload(sys)
sys.setdefaultencoding('utf-8')

seg_list = jieba.cut(sys.argv[1])
print "\n".join(seg_list)
