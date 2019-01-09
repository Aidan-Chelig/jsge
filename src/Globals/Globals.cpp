#include "Globals.h"

std::string Globals::workingDir = "";
std::string Globals::modDir = "";

Globals::Globals(){

}

Globals::~Globals(){

}

std::string Globals::getWorkingDir(){
  if(workingDir.empty()){
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  workingDir = buff;
  workingDir = workingDir + "/";
  modDir = workingDir + "Mods/";
  }
  return workingDir;
}

std::string Globals::getModDir(){
  if(modDir.empty()){
    getWorkingDir();
  }
  return modDir;
}
