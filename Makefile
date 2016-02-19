JNI = /usr/lib/jvm/java-1.7.0-openjdk-amd64
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(JNI)/jre/lib/amd64/server:/usr/local/lib/libraryController

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
	g++ -Wall -g -o controller/libraryController/mainController.o \
	-I controller/include \
	-L $(JNI)/jre/lib/amd64/server/ \
	-I $(JNI)/include/ \
	-I $(JNI)/include/linux/ \
	-c -fPIC controller/src/mainController.cpp -ljvm -Wno-write-strings

generate.so: controller/libraryController/mainController.o
	g++ controller/libraryController/mainController.o -shared -o controller/libraryController/libmaincontroller-1.0.so

run: generate.class generate.bin generate.o generate.so
	echo -e "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(JNI)/jre/lib/amd64/server:/usr/local/lib/libraryController" >> ~/.bashrc
	rm -f controller/libraryController/*.o &&\
	cp -avr controller/libraryController /usr/local/lib &&\
	cd /usr/local/lib/libraryController && sudo ln -f -s libmaincontroller-1.0.so libmaincontroller.so; 2> /dev/null
	cp config/*.pc /usr/lib/pkgconfig
	ldconfig
	cd && cd main_controller && ./control

clean:
	rm -rf class/*.class control *.log controller/libraryController/*.so /usr/local/lib/libraryController