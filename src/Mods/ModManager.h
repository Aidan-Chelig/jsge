#ifndef MODMANAGER_H_
#define MODMANAGER_H_

#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <vector>
#include "Mod.h"
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif


class ModManager {
  
public:
  ModManager();
  ~ModManager();

  void Init();
  


private:
};

#endif /* ModManager_h */
