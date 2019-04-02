#ifndef MODMANAGER_H_
#define MODMANAGER_H_

#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "Mod.h"
#include "../Utils/FileUtils.h"
#include "../Utils/Globals.h"
#include "libplatform/libplatform.h"
#include "v8.h"
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
using json = nlohmann::json;


class ModManager {
  
public:
  ModManager();
  ~ModManager();

  v8::Isolate* _isolate;

  void Init(char* argv);
  


private:
  std::vector<Mod> Mods;
};

#endif /* ModManager_h */
