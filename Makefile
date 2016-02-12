JNI = /usr/lib/jvm/java-7-openjdk-amd64

all: run

helloWorld.class: helloWorld.java
	$(JNI)/bin/javac helloWorld.java

hello_world: hello_world.c
	gcc -o hello \
	-L $(JNI)/jre/lib/amd64/server/ \
	-I $(JNI)/include/ \
	-I $(JNI)/include/linux/ \
	hello_world.c -ljvm

run: helloWorld.class hello_world
	export LD_LIBRARY_PATH="$(JNI)/jre/lib/amd64/server/"
	./hello

clean:
	rm -f helloWorld.class hello *.log
