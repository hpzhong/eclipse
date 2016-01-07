'''
@author: zhonghuiping
'''


def fun(count):
    sum = 0
    for i in xrange(count+1):
        while i > 0:
            if i % 10 == 1 :
                sum += 1
            i /= 10
    return sum
#print fun(100)
def wh(a):
    while a!=0:
        print a,
        print
        a-=1
    else:
        print "end"

wh(5)
for i in "Hello":
    print i
    
else:
    print "Hello"