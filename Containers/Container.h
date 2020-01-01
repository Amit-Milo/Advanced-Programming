//
// Created by amit on 23/12/2019.
//

#ifndef EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_
#define EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_

#include "MapsContainer.h"
#include "SocketsContainer.h"
#include "../InterpreterFiles/Interpreter.h"

class Container {
  friend class ConnectControlClientCommand;
  friend class OpenDataServerCommand;
  friend class BlockCommand;
  friend class Parser;

  Interpreter interpreter;
  MapsContainer maps;
  SocketsContainer sockets;
};

#endif //EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_