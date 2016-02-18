#!/usr/bin/env python
__author__ = 'kaibr'

import urllib
import urllib2
import re
import os

class Spider:
    def __init__(self, siteURL):
        self.siteURL = siteURL 
        self.user_agent = 'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6'
        # init headers
        self.headers = {'User-Agent' : self.user_agent}

    def getPage(self, name):
        url = self.siteURL + name
        print url
        request = urllib2.Request(url, headers = self.headers)
        try:
            response = urllib2.urlopen(request)
            return response.read().decode('utf-8')
        except urllib2.URLError,e:
            if hasattr(e,"reason"):
                print url + "linked fail, error reason is " + e.reason
                return None
    def getAllImg(self, name):
        page = self.getPage(name)
        # print page
        if(page is not None):
            pattern = re.compile("<dt class='gallery-icon'.*?<a href='(.*?)'", re.S)
            items = re.findall(pattern, page)
            self.saveImgs(items,name)
    def saveImgs(self,images,name):
        print "Found %d pictures" % len(images)
        self.mkdir(name)
        print "Pleas waiting, pictures are saving ..."
        for imageURL in images:
            # print imageURL
            fileName = name +'/'+imageURL.split('/')[-1]
            self.saveImg(imageURL,fileName)
    def saveImg(self,imageURL,fileName):
        u = urllib.urlopen(imageURL)
        data = u.read()
        f = open(fileName, 'wb')
        f.write(data)
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
            print "The directory " + path + "is created"
            return False
if __name__ == "__main__":
    spider = Spider('http://www.mmxyz.net/')
    for i in range(1500, 1501):
        spider.getAllImg("rosi-%d"%i)
    print "END"
