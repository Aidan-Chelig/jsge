#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "Entity.h"

class System {

public:
  System();
  System(int);
  ~System();

  int getMask() { return mask; }

  void update(Entity* entities);

protected:
  int mask;

};

#endif