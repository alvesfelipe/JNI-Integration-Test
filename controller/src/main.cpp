#include "mainController.h"

int main(int argc, char **argv){

	MainController *mc = new MainController();
    //jni pointer to a structure storing all JNI function pointers
    JNIEnv *env;

    env = mc->createVm("/home/felipe/main_controller/class_test");
    mc->callHello(env);

    return 0;
}