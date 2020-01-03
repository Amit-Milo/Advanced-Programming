//
// Created by amit on 23/12/2019.
//

#ifndef EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_
#define EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_

#include "MapsContainer.h"
#include "SocketsContainer.h"

class Interpreter;

class Container {
  friend class ConnectControlClientCommand;
  friend class OpenDataServerCommand;
  friend class BlockCommand;
  friend class Parser;
  friend class Interpreter;
  friend class CalculationTokensCreatorChecker;
  friend class TokensToExpressionConverter;
  friend class VarsSetter;

  Interpreter* interpreter;
  MapsContainer maps;
  SocketsContainer sockets;

  bool serverConnected = false;

 public:
  explicit Container(Interpreter* inter) : interpreter(inter) {}
  void SetInterpreter(Interpreter *interpreter) {
    Container::interpreter = interpreter;
  }
  Interpreter *GetInterpreter() const {
    return interpreter;
  }

};

#endif //EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_
