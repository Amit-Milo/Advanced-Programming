//
// Created by amit on 23/12/2019.
//

#ifndef EX3__MAPSCONTAINER_H_
#define EX3__MAPSCONTAINER_H_

#include <mutex>
#include <string>
#include <unordered_map>
#include <list>

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
  unordered_map<string, list<string> > simulatorToProgramWrapping;
  unordered_map<string, Command *> commands;

  /**
   * create the map of the simulator to program vars wrapping with all the sim var names.
   */
  void createSimulatorToProgramWrappingMap(); //TODO amit
  /**
   * create the commands map
   * @param container the contaienr that should be passed to all the commands
   */
  void createCommandsMap(Container *container);

 public:
  /**
   * just call the maps creation function.
   */
  MapsContainer(Container *container);

  /**
   * a getter for a key's value from the vars map
   */
  SimulatorVar *ReadVar(string key);

  /**
   * a setter for a var
   */
  void WriteVar(string key, double value);

  /**
   * @param index key to check
   * @return if index is inside the vars map
   */
  bool InVars(string index);

  /**
   * add a new var to the vars map
   * @param key var's name
   * @param value var's value
   */
  void AddVar(string key, SimulatorVar *value);
  /**
   * add a new command to the commands map
   * @param key command's name
   * @param value command's value
   */
  void AddCommand(string key, Command *value);

  /**
   * add a new wrapped var to the wrapped vars map
   * @param simVar the wrapper var from the simulator
   * @param progVar the wrapped var from the program
   */
  void AddWrappedVar(string simVar, string progVar);
};

#endif //EX3__MAPSCONTAINER_H_
