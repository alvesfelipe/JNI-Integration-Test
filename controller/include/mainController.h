#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_

#include <stdio.h>
#include <jni.h>

class MainController{

	private:
		int numero;
	
	public:
		//JNI functions
		JNIEnv* createVm();
		void callHello();

		//main controller functions
		void testOut();
		//constructor
		MainController();
		//destructor
		~MainController();	
};

#endif