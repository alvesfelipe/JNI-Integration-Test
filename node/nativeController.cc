#include <node.h>
#include <v8.h>
#include "mainController.h"

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  	Isolate* isolate = args.GetIsolate();
  
  	MainController *mc = new MainController();
  	//jni pointer to a structure storing all JNI function pointers
    //JNIEnv *env;

  	mc->testOut();
  	//env = mc->createVm("/home/felipe/main_controller/class_test");
    mc->callHello(mc->createVm("/home/felipe/main_controller/class_test"));

	//audio path to nodejs
	args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "sumarize", Method);
}

NODE_MODULE(addon, init);

}
