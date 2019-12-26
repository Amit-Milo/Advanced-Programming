//
// Created by amit on 23/12/2019.
//

#ifndef EX3__MAPSCONTAINER_H_
#define EX3__MAPSCONTAINER_H_

#include <string>
#include <unordered_map>
#include "../SimulatorVar.h"
#include "../Commands/Command.h"

#include "../Commands/OpenDataServerCommand.h"
#include "../Commands/ConnectControlClientCommand.h"

#include "../Commands/VarCommand.h"
#include "../Commands/VarCommands/ChangeValueCommand.h"
#include "../Commands/VarCommands/EqualSignVarCommand.h"
#include "../Commands/VarCommands/RightArrowVarCommand.h"
#include "../Commands/VarCommands/LeftArrowVarCommand.h"
#include "../Commands/BlockCommand.h"

#include "../Commands/BlockCommands/WhileCommand.h"
#include "../Commands/BlockCommands/IfCommand.h"

#include "SimulatorVar.h"

#define NEW_VALUE_COMMAND string("newValueCommand")
#define VAR_KEYWORD string("var")

using namespace std;

class MapsContainer {
  // Those classes need to use the maps.
  friend class ConnectControlClientCommand;
  friend class OpenDataServerCommand;
  friend class Parser;
  friend class VarCommand;

  unordered_map<string, Command *> commandsMap;
  unordered_map<string, SimulatorVar *> progVars;
  unordered_map<string, SimulatorVar *> simulatorVars;

  void setCommandsMap();

 public:
  MapsContainer();
  ///////////////////////////////////maybe maps dont release the pointers in the values
};

#endif //EX3__MAPSCONTAINER_H_
