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
  Interpreter *interpreter;
  MapsContainer *maps;
  SocketsContainer sockets;

 public:
  explicit Container(Interpreter *inter, MapsContainer *maps_container) : interpreter(inter), maps(maps_container) {}
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
  SocketsContainer &GetSockets() {
    return sockets;
  }
  virtual ~Container() {
    delete interpreter;
    delete maps;
  }

};

#endif //EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_
