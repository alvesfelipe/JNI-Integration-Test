// summ.cc
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
  
  printf("\n\n");
  mainController *ex = new mainController();
  ex->printArguments();
  printf("\n\n");

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "sumarize", Method);
}

NODE_MODULE(addon, init)

}  // namespace demo
