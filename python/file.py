'''
@author: zhonghuiping
'''
file = open("tmp.txt",'w')
file.write("Hello, World")
file.close()

try:
    fn = input("Enter file name:")
    fo = open(fn, 'r')
    for el in fo:
        print(el, end=' ') 
    fo.close()
except IOError as e:
    print("file open error:", e)