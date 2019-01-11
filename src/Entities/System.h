#ifndef SYSTEM_H_
#define SYSTEM_H_

class System {

public:
  System();
  System(int);
  ~System();

  int getMask() { return mask; }

protected:
  int mask;

};

#endif