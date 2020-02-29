#include <napi.h>

Napi::String Greeting(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Hello from C++");
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "greeting"),
                Napi::Function::New(env, Greeting));
    return exports;
}

NODE_API_MODULE(greeting, Init)