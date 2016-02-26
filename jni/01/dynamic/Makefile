CFLAGS+=-I/usr/lib/jvm/java-7-openjdk-amd64/include/ -L/usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/server/ -ljvm

native:
	gcc $(CFLAGS) -fPIC -shared native.c -o libhello.so

clean:
	rm -fr *.so *.class
