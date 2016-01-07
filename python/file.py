'''
@author: zhonghuiping
'''
file = open("tmp.txt",'w')
file.write("Hello, World")
file.close()

try:
    fn = raw_input("Enter file name:")
    fo = open(fn, 'r')
    for el in fo:
        print el, 
    fo.close()
except IOError, e:
    print "file open error:", e