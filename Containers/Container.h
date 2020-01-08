//
// Created by amit on 23/12/2019.
//

#ifndef EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_
#define EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_


#include "SocketsContainer.h"
#include <iostream>

class Interpreter;
class MapsContainer;

class Container {
  //classes that should access it's fields
  friend class ConnectControlClientCommand;
  friend class OpenDataServerCommand;
  friend class BlockCommand;
  friend class Interpreter;
  friend class CalculationTokensCreatorChecker;
  friend class TokensToExpressionConverter;
  friend class VarsSetter;
  friend class Parser;
  friend class PrintCommand;
  friend class VarCommand;
  friend class ChangeValueCommand;
  friend class EqualSignVarCommand;
  friend class LeftArrowVarCommand;
  friend class RightArrowVarCommand;
  friend class ArrowVarCommand;
  friend class SimulatorVar;
  friend class ConditionBlock;
  friend class FunctionCommand;

  Interpreter *interpreter;
  MapsContainer *maps;
  SocketsContainer sockets;
  //for function calls param:
  string tempParam;

 public:
  explicit Container(Interpreter *inter, MapsContainer *maps_container) : interpreter(inter), maps(maps_container) {}
  void SetInterpreter(Interpreter *interpreter_) {
    Container::interpreter = interpreter_;
  }
  Interpreter *GetInterpreter() const {
    return interpreter;
  }
  MapsContainer *GetMaps() const {
    return maps;
  }
  void SetMaps(MapsContainer *maps_) {
    Container::maps = maps_;
  }
  virtual ~Container() {
    delete interpreter;
    delete maps;
  }

};

#endif //EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_
