#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <streambuf>

class FileUtils {
  
public:
  static std::string readFileAsString(std::string path);
  static std::vector<std::string> getDirContents(std::string path);
private:
  FileUtils(){}

};

#endif /* FILEUTILS_H_ */
