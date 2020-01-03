//
// Created by amit on 23/12/2019.
//

#ifndef EX3__MAPSCONTAINER_H_
#define EX3__MAPSCONTAINER_H_

#include <mutex>
#include <string>
#include <unordered_map>

#include "../Commands/Command.h"
#include "../SimulatorVar.h"

using namespace std;

class MapsContainer {
  // Those classes need to use the maps.
  friend class ConnectControlClientCommand;
  friend class Interpreter;
  friend class OpenDataServerCommand;
  friend class Parser;
  friend class VarCommand;

  mutex readers_lock;
  mutex writers_lock;

  unordered_map<string, SimulatorVar*> vars;
  unordered_map<string, Command*> commands;


 public:
  SimulatorVar* ReadVar(string key);

  void WriteVar(string key, double value);

  bool InVars(string index);
};

#endif //EX3__MAPSCONTAINER_H_
