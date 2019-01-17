#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_

#include "Entity.h"
#include <vector>

class EntityManager {

public:
  EntityManager();
  ~EntityManager();

  Entity& createEntity();
  Entity* getEntities();

private:
  std::vector<Entity> entities;

};

#endif
