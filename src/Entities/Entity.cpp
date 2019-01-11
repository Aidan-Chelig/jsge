#include "Entity.h"

Entity::Entity(){
}

Entity::~Entity(){
}

Component* Entity::getComponents(){
  return components.data();
}

int Entity::getComponentMask(){
  unsigned int mask = 0;
  for (auto component: components){
    mask = mask | component.getMask();
  }
  return mask;
}