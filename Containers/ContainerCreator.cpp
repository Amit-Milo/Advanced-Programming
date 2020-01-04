//
// Created by yoav on 03/01/2020.
//

#include "ContainerCreator.h"
Container *ContainerCreator::createContainer() {
  //init the container
  Container *c = new Container(nullptr, nullptr);
  //create the Interpreter and set it
  Interpreter *i = new Interpreter(c);
  c->SetInterpreter(i);
  //create the MapsContainer and set it
  MapsContainer *m = new MapsContainer(c);
  c->SetMaps(m);
  return c;
}
