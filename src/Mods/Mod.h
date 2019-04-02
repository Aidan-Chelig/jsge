#ifndef MOD_H_
#define MOD_H_

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <nlohmann/json.hpp>
#include <string>
#include "libplatform/libplatform.h"
#include "v8.h"
using json = nlohmann::json;


class Mod {

  public:
    Mod(json m, std::string path, v8::Isolate* &isolate);
    ~Mod();

    

  private:
   json manifest; 
   std::string path;
   std::string name;
   std::map<std::string, std::string> assets;
   std::string index;
   v8::Isolate* isolate;


};

#endif /* MOD_H_ */
