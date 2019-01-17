#include "EntityManager.h"

EntityManager::EntityManager(){
}

EntityManager::~EntityManager(){
}

Entity& EntityManager::createEntity(){
  Entity entity;
  
  entities.push_back(entity);

  return entity;
}

Entity* EntityManager::getEntities(){
  return entities.data();
}
