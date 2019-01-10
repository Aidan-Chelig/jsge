#ifndef SCENE_H_
#define SCENE_H_

#include "Entity.h"
#include <vector>

class Scene {

public:
  Scene();
  Scene(int);
  ~Scene();

  Entity createEntity();

  void update();

private:
  std::vector<Entity> entities;

};

#endif /* SCENE_H_ */
