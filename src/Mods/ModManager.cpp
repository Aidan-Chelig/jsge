#include "ModManager.h"


std::vector<Mod> mods;


ModManager::ModManager(){

}

ModManager::~ModManager(){

}


void ModManager::Init(char* argv){

  v8::V8::InitializeICUDefaultLocation(argv);
  v8::V8::InitializeExternalStartupData(argv);
  std::unique_ptr<v8::Platform> platform = v8::platform::NewDefaultPlatform();
  v8::V8::InitializePlatform(platform.get());
  v8::V8::Initialize();
  // Create a new Isolate and make it the current one.
  v8::Isolate::CreateParams create_params;
  create_params.array_buffer_allocator =
  v8::ArrayBuffer::Allocator::NewDefaultAllocator();
  _isolate = v8::Isolate::New(create_params);

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
            Mod *tempmod = new Mod(json::parse(j), modpath, _isolate);
            mods.push_back(*tempmod);
          }
        }
      }
    }
  }
}
