#include "mainController.h"

JNIEnv* MainController::createVm(string pathClass){
    JavaVM* jvm;
    //jni pointer to a structure storing all JNI function pointers
    JNIEnv* env;
    JavaVMInitArgs args;
    JavaVMOption options;
    args.version = JNI_VERSION_1_6;
    args.nOptions = 1;
    
    //pass the path from .class by argument
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
        printf("Unable to Launch JVM %d\n",rv); 
        return NULL;
    }
    else{
        printf("\nINICIOU A JVM...\n");
        return env;
    }    
}

void MainController::callHello(JNIEnv* env){

    //JNIEnv *env = createVm();
    jclass hello_world_class;
    jmethodID main_method;
    jmethodID teste;
    //jmethodID square_method;
    //jmethodID power_method;
    //jint number=20;
    //jint exponent=3;
   
    hello_world_class = env->FindClass("HelloJNI");
    main_method = env->GetStaticMethodID(hello_world_class, "main", "([Ljava/lang/String;)V");
    teste = env->GetStaticMethodID(hello_world_class, "teste", "()V");
    //square_method = env->GetStaticMethodID(env, hello_world_class, "square", "(I)I");
    //power_method = env->GetStaticMethodID(env, hello_world_class, "power", "(II)I");
    env->CallStaticVoidMethod(hello_world_class, main_method);
    env->CallStaticVoidMethod(hello_world_class, teste);
    /*
    printf("%d squared is %d\n", number,
        env->CallStaticIntMethod(env, hello_world_class, square_method, number));
    printf("%d raised to the %d power is %d\n", number, exponent,
        env->CallStaticIntMethod(env, hello_world_class, power_method, number, exponent));
    */
}

void MainController::testOut(){
    printf("\nMETODO DO C++...\n");
}

MainController::MainController(){}

MainController::~MainController(){}