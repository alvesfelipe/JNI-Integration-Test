#include <stdio.h>
#include "/usr/lib/jvm/java-1.7.0-openjdk-amd64/include/jni.h"

#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_

class MainController{

	private:
		int numero;
	
	public:
		//JNI functions
		JNIEnv* create_vm(JavaVM **jvm);
		void invoke_class(JNIEnv* env);

		//main controller functions

		void imprime();

		//constructor
		MainController();
		//destructor
		~MainController();	
};

#endif