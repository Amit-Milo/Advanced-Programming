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

  mutex vars_readers_lock;
  mutex vars_writers_lock;

  mutex simulator_readers_lock;
  mutex simulator_writers_lock;

  mutex commands_readers_lock;
  mutex commands_writers_lock;

  unordered_map<string, SimulatorVar *> vars;
  unordered_map<string, list<string>* > simulatorToProgramWrapping;
  unordered_map<string, Command *> commands;

  // A list of the names of the variables declared in the simulator.
  const string names[SIMULATOR_VARS_AMOUNT] = {"sim_vars_amount", "time_warp", "switches_magnetos", "heading-indicator_offset-deg",
                                         "altimeter_indicated-altitude-ft", "altimeter_pressure-alt-ft", "attitude-indicator_indicated-pitch-deg",
                                         "attitude-indicator_indicated-roll-deg", "attitude-indicator_internal-pitch-deg", "attitude-indicator_internal-roll-deg",
                                         "encoder_indicated-altitude-ft", "encoder_pressure-alt-ft", "gps_indicated-altitude-ft", "gps_indicated-ground-speed-kt",
                                         "gps_indicated-vertical-speed", "indicated-heading-deg", "magnetic-compass_indicated-heading-deg", "slip-skid-ball_indicated-slip-skid",
                                         "turn-indicator_indicated-turn-rate", "vertical-speed-indicator_indicated-speed-fpm", "flight_aileron", "flight_elevator",
                                         "flight_rudder", "flight_flaps", "engine_throttle", "current-engine_throttle", "switches_master-avionics", "switches_starter",
                                         "active-engine_auto-start", "flight_speedbrake", "c172p_brake-parking", "engine_primer", "current-engine_mixture",
                                         "switches_master-bat", "switches_master-alt", "engine_rpm"};

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
