#ifndef ENTITY_H_
#define ENTITY_H_

#include "Vector3.h"
#include "Component.h"
#include <vector>

class Entity {

public:
  Entity();
  ~Entity();

  Component* getComponents();
  int getComponentMask();
 
private:
  std::vector<Component> components;

};

#endif /* ENTITY_H_ */