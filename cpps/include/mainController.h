#include <stdio.h>
#include <jni.h>

#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_

class MainController{

	private:
		int numero;
	
	public:
		//JNI functions
		JNIEnv* create_vm(JavaVM *jvm);
		void invoke_class(JNIEnv* env);

		//main controller functions

		//constructor
		MainController();
		//destructor
		~MainController();	
};

#endif