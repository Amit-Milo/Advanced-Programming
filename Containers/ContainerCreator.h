//
// Created by yoav on 03/01/2020.
//

#ifndef EX3__CONTAINERCREATOR_H_
#define EX3__CONTAINERCREATOR_H_

#include "Container.h"
#include "../InterpreterFiles/Interpreter.h"

class ContainerCreator {
 public:
  /**
   * handle the creation of a container which is problematic because of double-sided components
   * @return the valid container
   */
  Container *createContainer();
};

#endif //EX3__CONTAINERCREATOR_H_
