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
  friend class PrintCommand;
  friend class VarCommand;

  Interpreter *interpreter;
  MapsContainer *maps;
  SocketsContainer sockets;

  bool serverConnected = false;

 public:
  explicit Container(Interpreter *inter, MapsContainer *maps_container) : interpreter(inter), maps(maps_container) {}
  explicit Container() : interpreter(nullptr), maps(nullptr) {}
  void SetInterpreter(Interpreter *interpreter) {
    Container::interpreter = interpreter;
  }
  Interpreter *GetInterpreter() const {
    return interpreter;
  }
  MapsContainer *GetMaps() const {
    return maps;
  }
  void SetMaps(MapsContainer *maps) {
    Container::maps = maps;
  }

};

#endif //EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_
