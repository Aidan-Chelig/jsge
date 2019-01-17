#include "Mod.h"

Mod::Mod(json m, std::string path){
 manifest = m;
 std::cout << "Mod " << m["name"].get<std::string>() << " created!" << std::endl;
}

Mod::~Mod(){

}
