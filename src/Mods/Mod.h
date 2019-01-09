#ifndef MOD_H_
#define MOD_H_

#include <stdio.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
using json = nlohmann::json;


class Mod {

  public:
    Mod(json m, std::string path);
    ~Mod();

    

  private:
   json manifest; 

};

#endif /* MOD_H_ */
