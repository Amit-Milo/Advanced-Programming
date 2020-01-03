//
// Created by yoav on 03/01/2020.
//

#include "ContainerCreator.h"
Container *ContainerCreator::createContainer() {
  Container *c = new Container(nullptr, nullptr);
  Interpreter *i = new Interpreter(c);
  c->SetInterpreter(i);
  MapsContainer *m = new MapsContainer(c);
  c->SetMaps(m);
  return c;
}
