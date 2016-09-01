#include <nan.h>

void Crash(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(*static_cast<int*>(0));
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("crash").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Crash)->GetFunction());
}

NODE_MODULE(crash, Init)
