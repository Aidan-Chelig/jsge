#ifndef TRANSFORMCOMPONENT_H_
#define TRANSFORMCOMPONENT_H_

#include "Vector3.h"
#include "Vector2.h"

typedef struct {
  Vector3 position;
  Vector2 scale;
  float rotation;
} TransformComponent;

#endif /* TRANSFORMCOMPONENT_H_ */