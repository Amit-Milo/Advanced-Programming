//
// Created by amit on 23/12/2019.
//

#ifndef EX3__MAPSCONTAINER_H_
#define EX3__MAPSCONTAINER_H_

#include <string>
#include <unordered_map>

#include "Container.h"
#include "SimulatorVar.h"

using namespace std;

class MapsContainer: public Container {
  // Those classes need to use the maps.
  friend class VarCommand;
  friend class Parser;

  unordered_map<string, SimulatorVar*> progVars;
  unordered_map<string, SimulatorVar*> simulatorVars;
};

#endif //EX3__MAPSCONTAINER_H_
