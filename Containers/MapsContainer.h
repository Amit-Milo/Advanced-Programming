//
// Created by amit on 23/12/2019.
//

#ifndef EX3__MAPSCONTAINER_H_
#define EX3__MAPSCONTAINER_H_

#include <string>
#include <unordered_map>


#include "../SimulatorVar.h"
#include "../Commands/Command.h"

#define NEW_VALUE_COMMAND string("newValueCommand")
#define VAR_KEYWORD string("var")

using namespace std;

class MapsContainer {
  // Those classes need to use the maps.
  friend class ConnectControlClientCommand;
  friend class OpenDataServerCommand;
  friend class Parser;
  friend class VarCommand;
  friend class Interpreter;
  friend class CalculationTokensCreatorChecker;
  friend class TokensToExpressionConverter;
  friend class VarsSetter;

  unordered_map<string, Command *> commands;
  unordered_map<string, SimulatorVar *> vars;

  Container* container;

  void setCommandsMap();

 public:
  MapsContainer();
  ///////////////////////////////////maybe maps dont release the pointers in the values
  void WriteProgVar(string key);
  void WriteSimulatorVar(string key);
};

#endif //EX3__MAPSCONTAINER_H_
