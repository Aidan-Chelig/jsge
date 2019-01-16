#include "FileUtils.h"


std::vector<std::string> FileUtils::getDirContents(std::string path){
  DIR *dir;
  struct dirent *ent;
  std::vector<std::string> dirs;
  if((dir = opendir(path.c_str())) != NULL) {
    seekdir(dir, 2);
    while ((ent = readdir (dir)) != NULL) {
      dirs.push_back(std::string(ent->d_name));
    }
    closedir(dir);
  } else {
    perror ("");
  }
  return dirs;
}

std::string readFileAsString(std::string path){
  std::ifstream t(path);
  std::string str;

  t.seekg(0, std::ios::end);
  str.reserve(t.tellg());
  t.seekg(0, std::ios::beg);

  str.assign((std::istreambuf_iterator<char>(t)),
              std::istreambuf_iterator<char>());
  return str;
}
