#ifndef ModManager_h
#define ModManager_h

#include <stdio.h>
#include <iostream>
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

  void init();
  


private:
};

#endif /* ModManager_h */
