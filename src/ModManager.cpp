#include "ModManager.h"

ModManager::ModManager(){

}

ModManager::~ModManager(){

}

void ModManager::init(){
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  std::cout << current_working_dir << std::endl;
}

