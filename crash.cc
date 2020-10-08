#include <nan.h>

void Crash(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(*static_cast<int*>(0));
}

void Init(v8::Local<v8::Object> exports) {
  Nan::Set(exports,
           Nan::New("crash").ToLocalChecked(),
           Nan::GetFunction(Nan::New<v8::FunctionTemplate>(Crash)).ToLocalChecked());
}

NODE_MODULE(crash, Init)
