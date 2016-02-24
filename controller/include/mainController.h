#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_

#include <stdio.h>
#include <jni.h>
#include <string.h>
#include <iostream>

using namespace std;

class MainController{

	private:
		int numero;
	
	public:
		//JNI functions
		JNIEnv* createVm(string pathClass);
		void callHello(JNIEnv* env);

		//main controller functions
		void testOut();
		//constructor
		MainController();
		//destructor
		~MainController();	
};

#endif