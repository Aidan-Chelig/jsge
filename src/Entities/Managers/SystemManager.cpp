#include "SystemManager.h"

SystemManager::SystemManager(EntityManager& entityManager) : entityManager(entityManager){
}

SystemManager::~SystemManager(){
}

template<class System> void SystemManager::registerSystem(){
  systems.push_back(new System());
}

void SystemManager::update(){
  Entity* entities = entityManager.getEntities();
  for (auto system : systems){
    std::vector<Entity> maskedEntities;
    for (unsigned int i = 0; i < sizeof(entities)/sizeof(Entity); i++){
      if (entities[i].getComponentMask() == system.getMask()){
        maskedEntities.push_back(entities[i]);
      }
    }
    system.update(maskedEntities.data());
  }
}