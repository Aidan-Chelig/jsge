#ifndef TRANSFORMCOMPONENT_H_
#define TRANSFORMCOMPONENT_H_

#include "Component.h"
#include "Vector3.h"
#include "Vector2.h"

class TransformComponent : Component {

public:
  static const int MASK = 1 << 0;

  TransformComponent();
  ~TransformComponent();

  Vector3 position;
  Vector2 scale;
  float rotation;

};

#endif /* TRANSFORMCOMPONENT_H_ */