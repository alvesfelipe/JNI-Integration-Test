JNI = /usr/lib/jvm/java-1.7.0-openjdk-amd64

all: run

generate.class: java_test/HelloJNI.java
	$(JNI)/bin/javac -d ./class java_test/HelloJNI.java

generate.bin: controller/src/main.cpp
	g++ -o control \
	-I controller/include \
	-L $(JNI)/jre/lib/amd64/server/ \
	-I $(JNI)/include/ \
	-I $(JNI)/include/linux/ \
	controller/src/*.cpp -ljvm -Wno-write-strings

generate.o: controller/src/mainController.cpp
	g++ -Wall -g -o mainController.o \
	-I controller/include \
	-L $(JNI)/jre/lib/amd64/server/ \
	-I $(JNI)/include/ \
	-I $(JNI)/include/linux/ \
	-c -fPIC controller/src/mainController.cpp -ljvm -Wno-write-strings

generate.so: mainController.o
	g++ mainController.o -shared -o mainController.so

run: generate.class generate.bin generate.o generate.so
	export LD_LIBRARY_PATH="$(JNI)/jre/lib/amd64/server/"
	./control && ls class/

clean:
	rm -f class/*.class control *.log *.o *.so