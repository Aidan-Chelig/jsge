#ifndef COMPONENT_H_
#define COMPONENT_H_

class Component {

public:
  Component();
  Component(int);
  ~Component();

  int getMask() { return mask; }

protected:
  int mask;

};

#endif /* COMPONENT_H_ */