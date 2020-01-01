//
// Created by amit on 23/12/2019.
//

#ifndef EX3__MAPSCONTAINER_H_
#define EX3__MAPSCONTAINER_H_

#include <string>
#include <unordered_map>

using namespace std;

class MapsContainer {
  // Those classes need to use the maps.
  friend class ConnectControlClientCommand;
  friend class OpenDataServerCommand;
  friend class Parser;
  friend class VarCommand;

  unordered_map<string, SimulatorVar*> progVars;
  unordered_map<string, SimulatorVar*> simulatorVars;

 public:
  SimulatorVar* ReadProgVar(string key);
  SimulatorVar* ReadSimulatorVar(string key);

  void WriteProgVar(string key);
  void WriteSimulatorVar(string key);
};

#endif //EX3__MAPSCONTAINER_H_
