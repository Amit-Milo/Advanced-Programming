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

#define SIMULATOR_VARS_AMOUNT 36

using namespace std;

class MapsContainer {
  // Those classes need to use the maps
  friend class ConnectControlClientCommand;
  friend class Interpreter;
  friend class OpenDataServerCommand;
  friend class VarCommand;
  friend class CalculationTokensCreatorChecker;
  friend class TokensToExpressionConverter;
  friend class VarsSetter;
  friend class BlockCommand;
  friend class Parser;

  mutex vars_lock;

  mutex simulator_lock;

  mutex commands_lock;

  unordered_map<string, SimulatorVar *> vars;
  unordered_map<string, list<string> *> simulatorToProgramWrapping;
  unordered_map<string, Command *> commands;

  // A list of the names of the variables declared in the simulator.
  const string names[SIMULATOR_VARS_AMOUNT] = {
          "/instrumentation/airspeed-indicator/indicated-speed-kt",
          "/sim/time/warp",
          "/controls/switches/magnetos",
          "/instrumentation/heading-indicator/offset-deg",
          "/instrumentation/altimeter/indicated-altitude-ft",
          "/instrumentation/altimeter/pressure-alt-ft",
          "/instrumentation/attitude-indicator/indicated-pitch-deg",
          "/instrumentation/attitude-indicator/indicated-roll-deg",
          "/instrumentation/attitude-indicator/internal-pitch-deg",
          "/instrumentation/attitude-indicator/internal-roll-deg",
          "/instrumentation/encoder/indicated-altitude-ft",
          "/instrumentation/encoder/pressure-alt-ft",
          "/instrumentation/gps/indicated-altitude-ft",
          "/instrumentation/gps/indicated-ground-speed-kt",
          "/instrumentation/gps/indicated-vertical-speed",
          "/instrumentation/heading-indicator/indicated-heading-deg",
          "/instrumentation/magnetic-compass/indicated-heading-deg",
          "/instrumentation/slip-skid-ball/indicated-slip-skid",
          "/instrumentation/turn-indicator/indicated-turn-rate",
          "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
          "/controls/flight/aileron",
          "/controls/flight/elevator",
          "/controls/flight/rudder",
          "/controls/flight/flaps",
          "/controls/engines/engine/throttle",
          "/controls/engines/current-engine/throttle",
          "/controls/switches/master-avionics",
          "/controls/switches/starter",
          "/engines/active-engine/auto-start",
          "/controls/flight/speedbrake",
          "/sim/model/c172p/brake-parking",
          "/controls/engines/engine/primer",
          "/controls/engines/current-engine/mixture",
          "/controls/switches/master-bat",
          "/controls/switches/master-alt",
          "/engines/engine/rpm"
      };

  /**
   * create the map of the simulator to program vars wrapping with all the sim var names.
   */
  void createSimulatorToProgramWrappingMap();
  /**
   * create the commands map
   * @param container the container that should be passed to all the commands
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
   * delete the var with the input name from the vars map.
   * @param key the var to delete.
   */
  void DeleteVar(string key);
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

  /**
   * Write a value got from the simulator to all wrapped variables.
   * @param string simVar the wrapper var from the simulator.
   * @param value the value to assign, received by the simulator.
   */
  void WriteWrappedVar(string simVar, float value);
};

#endif //EX3__MAPSCONTAINER_H_
