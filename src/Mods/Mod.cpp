#include "Mod.h"

Mod::Mod(json m, std::string p, v8::Isolate* &i){
  manifest = m;
  path = p;
  isolate = i;
  std::cout << "Mod " << m["name"].get<std::string>() << " created!" << std::endl;
  //set all variables if the its in the json
  
  v8::Isolate::Scope isolate_scope(isolate);
    // Create a stack-allocated handle scope.
    v8::HandleScope handle_scope(isolate);
    // Create a new context.
    v8::Local<v8::Context> context = v8::Context::New(isolate);
    // Enter the context for compiling and running the hello world script.
    v8::Context::Scope context_scope(context);
    {
      // Create a string containing the JavaScript source code.
      v8::Local<v8::String> source =
          v8::String::NewFromUtf8(isolate, "'Hello' + ', World!'",
                                  v8::NewStringType::kNormal)
              .ToLocalChecked();
      // Compile the source code.
      v8::Local<v8::Script> script =
          v8::Script::Compile(context, source).ToLocalChecked();
      // Run the script to get the result.
      v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();
      // Convert the result to an UTF8 string and print it.
      v8::String::Utf8Value utf8(isolate, result);
  //std::cout << "Mod " << m["name"].get<std::string>() << " created!" << std::endl;
      //printf("%s\n", *utf8);
  std::cout << "Mod " << *utf8  << std::endl;
    }


}

Mod::~Mod(){

}
