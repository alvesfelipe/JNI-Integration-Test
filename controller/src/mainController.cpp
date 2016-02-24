#include "mainController.h"

JNIEnv* MainController::createVm(string pathClass){
    JavaVM* jvm;
    //jni pointer to a structure storing all JNI function pointers
    JNIEnv* env;
    JavaVMInitArgs args;
    JavaVMOption options;
    args.version = JNI_VERSION_1_6;
    args.nOptions = 1;
    
    //passing the path from .class by argument
    string path = "-Djava.class.path=";
    path += pathClass;
    char* p = new char[path.size() + 1];
    std::copy(path.begin(), path.end(), p);
    p[path.size()] = '\0';
    
    options.optionString = p;//"-Djava.class.path=/home/felipe/main_controller/class_test";
    args.options = &options;
    args.ignoreUnrecognized = 0;
    int rv;
    
    rv = JNI_CreateJavaVM(&jvm, (void**)&env, &args);
    
    if (rv < 0 || !env){
        printf("NAO PODE INICIAR A JVM %d\n",rv); 
        return NULL;
    }
    else{
        printf("\nINICIOU A JVM...\n");
        return env;
    }    
}

void MainController::callHello(JNIEnv* env){

    jclass hello_world_class;
    jmethodID main_method;
    jmethodID teste;
   
    hello_world_class = env->FindClass("HelloJNI");
    main_method = env->GetStaticMethodID(hello_world_class, "main", "([Ljava/lang/String;)V");
    teste = env->GetStaticMethodID(hello_world_class, "teste", "()V");

    env->CallStaticVoidMethod(hello_world_class, main_method);
    env->CallStaticVoidMethod(hello_world_class, teste);
}

void MainController::testOut(){
    printf("\nMETODO DO C++...\n");
}

MainController::MainController(){}

MainController::~MainController(){}