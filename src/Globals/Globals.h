#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <vector>
#ifdef WINDOWS

#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif


class Globals {
  
public:
  Globals();
  ~Globals();

  static std::string getWorkingDir();
  static std::string getModDir();

private:
  static std::string workingDir;
  static std::string modDir;

};

#endif /* GLOBALS_H_ */
