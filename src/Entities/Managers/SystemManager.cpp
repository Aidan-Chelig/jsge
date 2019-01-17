#include "SystemManager.h"

SystemManager::SystemManager(){
}

SystemManager::~SystemManager(){
}

template<class System> void SystemManager::registerSystem(){
  systems.push_back(new System());
}

void SystemManager::update(){
  for (auto system : systems){
    
  }
}