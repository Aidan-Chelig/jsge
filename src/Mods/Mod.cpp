#include "Mod.h"

Mod::Mod(json m, std::string path){
 manifest = m;
 std::cout << path << std::endl;
}

Mod::~Mod(){

}
