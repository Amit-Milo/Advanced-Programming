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

  int open_threads = 0;
  bool program_runs = true;

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

  /**
  * Notify that a new thread was created.
  */
  void AddThread() {this->open_threads++;}
  
  /**
  * Notify that a thread has finished.
  */
  void ReleaseThread() {this->open_threads--;}
  
  /**
  * Are any threads open?
  * @return true if there are open threads, false otherwise.
  */
  bool ThreadsOpen() {return this->open_threads > 0;}

  /**
  * Is the program running?
  * @return true if the program is still running, false otherwise.
  */
  bool ProgramRuns() {return this->program_runs;}
  
  /**
  * Handle finishing of the program.
  */
  void TerminateProgram() {
    // Release sockets.
    this->sockets.ReleaseSockets();

    // Set the program runs variable to false in order to tell all threads that program has finished.
    this->program_runs = false;
  }
};

#endif //EX3_CMAKE_BUILD_DEBUG_CONTAINER_H_
