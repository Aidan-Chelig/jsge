#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <vector>

class FileUtils {
  
public:
  static std::string getDirContents();
  static std::string getFileAsString();

private:
  static std::string workingDir;
  static std::string modDir;
  Globals(){}

};

#endif /* GLOBALS_H_ */
