CFLAGS+=-I/usr/lib/jvm/java-7-openjdk-amd64/include/ -L/usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/server/ -ljvm

s:
	gcc $(CFLAGS) -fPIC -shared s.c -o libInstanceFieldAccess.so

clean:
	rm -fr libInstanceFieldAccess.so *.class
