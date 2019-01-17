#include "ModManager.h"


std::vector<Mod> mods;


ModManager::ModManager(){

}

ModManager::~ModManager(){

}


void ModManager::Init(){
  std::vector<std::string> moddir = FileUtils::getDirContents(Globals::getModDir());

  std::vector<std::string> parModDir;

  for(std::vector<std::string>::iterator it = moddir.begin(); it != moddir.end(); ++it) {
    if(*it != "." && *it != ".."){
      parModDir = FileUtils::getDirContents((Globals::getModDir()) + "/" + *it);
      for(std::vector<std::string>::iterator at = parModDir.begin(); at != parModDir.end(); ++at){
        if(*at != "." && *at != ".."){
          if(*at == "manifest.json"){
            std::string modpath = (Globals::getModDir()) + "/" + *it;
            std::string j = FileUtils::readFileAsString(modpath + "/" + "manifest.json");
            Mod *tempmod = new Mod(json::parse(j), modpath);
            mods.push_back(*tempmod);


          }
        }
      }
    }
  }
}
