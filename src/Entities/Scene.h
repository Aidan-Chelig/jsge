#ifndef SCENE_H_
#define SCENE_H_

#include "EntityManager.h"
#include "SystemManager.h"
#include <vector>

class Scene {

public:
  Scene();
  ~Scene();

  void update();

private:
  EntityManager entityManager;
  SystemManager* systemManager;

};

#endif /* SCENE_H_ */
