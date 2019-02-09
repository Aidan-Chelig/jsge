#include "Mod.h"

Mod::Mod(json m, std::string p){
  manifest = m;
  path = p;
  std::cout << "Mod " << m["name"].get<std::string>() << " created!" << std::endl;
  //set all variables if the its in the json

}

Mod::~Mod(){

}
