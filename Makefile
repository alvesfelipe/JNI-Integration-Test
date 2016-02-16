JNI = /usr/lib/jvm/java-1.7.0-openjdk-amd64

all: run

helloWorld.class: java/HelloJNI.java
	$(JNI)/bin/javac -d ./class java/HelloJNI.java

hello_world: cpp/hello_world.c
	gcc -o hello \
	-L $(JNI)/jre/lib/amd64/server/ \
	-I $(JNI)/include/ \
	-I $(JNI)/include/linux/ \
	cpp/hello_world.c -ljvm

run: helloWorld.class hello_world
	export LD_LIBRARY_PATH="$(JNI)/jre/lib/amd64/server/"
	./hello

clean:
	rm -f class/*.class hello *.log