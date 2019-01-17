#ifndef SYSTEMMANAGER_H_
#define SYSTEMMANAGER_H_

#include "System.h"
#include <vector>

class SystemManager {

public:
  SystemManager();
  ~SystemManager();

  template<class System> void registerSystem();

  void update();

private:
  std::vector<System> systems;

};

#endif