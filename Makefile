JNI = /usr/lib/jvm/java-1.7.0-openjdk-amd64
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(JNI)/jre/lib/amd64/server:/usr/local/lib/libraryController

all: run

java.class: java_test/HelloJNI.java
	$(JNI)/bin/javac -d ./class_test java_test/HelloJNI.java

maincontroller.bin: controller/src/
	g++ -o control \
	-I controller/include \
	-L $(JNI)/jre/lib/amd64/server/ \
	-I $(JNI)/include/ \
	-I $(JNI)/include/linux/ \
	controller/src/*.cpp -fPIC -ljvm -Wno-write-strings

maincontroller.o: controller/src/
	g++ -Wall -g -o controller/libraryController/mainController.o -shared -fPIC \
	-I controller/include \
	-L $(JNI)/jre/lib/amd64/server/ \
	-I $(JNI)/include/ \
	-I $(JNI)/include/linux/ \
	-c -fPIC controller/src/mainController.cpp -ljvm -Wwrite-strings

maincontroller.so: controller/src/
	g++ -o controller/libraryController/libmaincontroller-1.0.so -I controller/include \
	-I $(JNI)/include/ controller/src/mainController.cpp -shared -fPIC \
	-L $(JNI)/jre/lib/amd64/server/ -ljvm

configure:
	#echo "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(JNI)/jre/lib/amd64/server:/usr/local/lib/libraryController" >> ~/.bashrc
	rm -f controller/libraryController/*.o &&\
	cp -avr controller/libraryController /usr/local/lib &&\
	cd /usr/local/lib/libraryController && sudo ln -f -s libmaincontroller-1.0.so libmaincontroller.so; 2> /dev/null
	cp config/*.pc /usr/lib/pkgconfig
	ldconfig
	#./control

node.js: node/test.js
	cd node && node-gyp configure build && node test.js

run: java.class maincontroller.bin maincontroller.o maincontroller.so configure node.js

clean:
	rm -rf class_test/*.class control *.log controller/libraryController/*.so /usr/local/lib/libraryController
	cd node && node-gyp clean