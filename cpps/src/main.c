#include "../include/mainController.h"

int main(int argc, char **argv){

	MainController *mc;
	mc = new MainController();
	mc->imprime();
/*
    JavaVM *jvm;
    JNIEnv *env;
    env = mc->create_vm(&jvm);
    if(env == NULL)
        return 1;
    mc->invoke_class(env);
  */  
    return 0;
}