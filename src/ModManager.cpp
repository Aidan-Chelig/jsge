#include "ModManager.h"

ModManager::ModManager(){

}

ModManager::~ModManager(){

}

 void parseMods(const char* directory){
  DIR *dir;
  struct dirent *ent;
  int folderCount = 0;
  int index = 0;
  const char* tempName;
  std::vector<std::string> modDirs;
  if ((dir = opendir (directory)) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      index++;
      if(index < 3)// the first 2 directorys are always . and .. ignore them
       continue; 

      tempName = ent->d_name;
      std::cout << tempName << std::endl;
      modDirs.push_back(std::string(tempName));
      //create array of mod struct
      folderCount++;
    }
    //loop again but this time populate the mod
    closedir(dir);
  } else {
    perror ("");
  }
}

void ModManager::init(){
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  std::cout << current_working_dir << std::endl;
  std::string mod_dir = current_working_dir + "/Mods";

  parseMods(mod_dir.c_str());
}

