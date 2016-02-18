#!/usr/bin/env python
__author__ = 'kaibr'

import urllib
import urllib2
import re
import os
import random

class Spider:
    def __init__(self, siteURL):
        self.siteURL = siteURL 
    def get_headers(self):
        f = open("user_agent_list.txt",'r')
        self.user_agent_list =f.readlines()
        self.user_agent = self.user_agent_list[random.randint(0,len(self.user_agent_list)-1)][:-1]
        # init headers
        self.headers = {'User-Agent' : self.user_agent}
        f.close()
    
    def getPage(self, name):
        url = self.siteURL + name
        print url
        request = urllib2.Request(url, headers = self.headers)
        try:
            response = urllib2.urlopen(request)
            return response.read().decode('utf-8')
        except urllib2.URLError,e:
            if hasattr(e,"reason"):
                print url + u" linked fail, error reason is " + e.reason
                return None
    def getAllImg(self, name):
        self.get_headers()
        page = self.getPage(name)
        # print page
        if(page is not None):
            pattern = re.compile('a href="http://ww3.sinaimg.cn/large/(.*?)" target', re.S)
            items = re.findall(pattern, page)
            self.saveImgs(items,name)
    def saveImgs(self,images,name):
        print "Found %d pictures" % len(images)
        print "Pleas waiting, pictures are saving ..."
        for imageURL in images:
            # print imageURL
            fileName = "pic/" + imageURL
            self.saveImg("http://ww3.sinaimg.cn/large/" + imageURL, fileName)
    def saveImg(self,imageURL, fileName):
        u = urllib.urlopen(imageURL)
        data = u.read()
        f = open(fileName, 'wb')
        f.write(data)
        print "get from " +imageURL
        print "Saving " + fileName
        f.close()
    def mkdir(self,path):
        path = path.strip()
        isExists = os.path.exists(path)
        if not isExists:
            print "Create directory: " + path
            os.makedirs(path)
            return True
        else:
            print "The directory " + path + " is created"
            return False
if __name__ == "__main__":
    spider = Spider('http://jandan.net/ooxx/')
    spider.mkdir("pic/")
    for i in range(1700, 1842):
        spider.getAllImg("page-%d#comments"%i)
    print "END"
