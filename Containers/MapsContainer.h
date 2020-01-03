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

class Container;

class MapsContainer {
  // Those classes need to use the maps
  friend class ConnectControlClientCommand;
  friend class Interpreter;
  friend class OpenDataServerCommand;
  friend class Parser;
  friend class VarCommand;
  friend class CalculationTokensCreatorChecker;
  friend class TokensToExpressionConverter;
  friend class VarsSetter;
  friend class BlockCommand;

  mutex readers_lock;
  mutex writers_lock;

  unordered_map<string, SimulatorVar *> vars;
  unordered_map<string, Command *> commands;

  void createCommandsMap(Container *container);

 public:
  MapsContainer(Container *container);

  SimulatorVar *ReadVar(string key);

  void WriteVar(string key, double value);

  bool InVars(string index);

  void AddVar(string key, SimulatorVar *value);
  void AddCommand(string key, Command * value);
};

#endif //EX3__MAPSCONTAINER_H_
