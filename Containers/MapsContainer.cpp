//
// Created by amit on 01/01/2020.
//

#include "MapsContainer.h"

#include "../Commands/ConnectControlClientCommand.h"
#include "../Commands/OpenDataServerCommand.h"
#include "../Commands/SleepCommand.h"
#include "../Commands/PrintCommand.h"
#include "../Commands/BlockCommands/WhileCommand.h"
#include "../Commands/BlockCommands/IfCommand.h"
#include "../Commands/VarCommands/ChangeValueCommand.h"
#include "../Commands/VarCommands/EqualSignVarCommand.h"
#include "../Commands/VarCommands/ArrowCommands/RightArrowVarCommand.h"
#include "../Commands/VarCommands/ArrowCommands/LeftArrowVarCommand.h"
#include "../Parser.h"

#define SIMULATOR_VARS_AMOUNT 36

void MapsContainer::createCommandsMap(Container *container) {
  this->AddCommand("openDataServer", new OpenDataServerCommand(container, SIMULATOR_VARS_AMOUNT));
  this->AddCommand("connectControlClient", new ConnectControlClientCommand(container));
  this->AddCommand("Sleep", new SleepCommand(container));
  this->AddCommand("Print", new PrintCommand(container));
  this->AddCommand("while", new WhileCommand(container));
  this->AddCommand("if", new IfCommand(container));
  this->AddCommand(NEW_VALUE_COMMAND, new ChangeValueCommand(container));
  this->AddCommand("=", new EqualSignVarCommand(container));
  this->AddCommand("->", new RightArrowVarCommand(container));
  this->AddCommand("<-", new LeftArrowVarCommand(container));
}

void MapsContainer::createSimulatorToProgramWrappingMap() {
  // A list of the names of the variables declared in the simulator.
  string names[SIMULATOR_VARS_AMOUNT] = {"sim_vars_amount", "time_warp", "switches_magnetos", "heading-indicator_offset-deg",
                      "altimeter_indicated-altitude-ft", "altimeter_pressure-alt-ft", "attitude-indicator_indicated-pitch-deg",
                      "attitude-indicator_indicated-roll-deg", "attitude-indicator_internal-pitch-deg", "attitude-indicator_internal-roll-deg",
                      "encoder_indicated-altitude-ft", "encoder_pressure-alt-ft", "gps_indicated-altitude-ft", "gps_indicated-ground-speed-kt",
                      "gps_indicated-vertical-speed", "indicated-heading-deg", "magnetic-compass_indicated-heading-deg", "slip-skid-ball_indicated-slip-skid",
                      "turn-indicator_indicated-turn-rate", "vertical-speed-indicator_indicated-speed-fpm", "flight_aileron", "flight_elevator",
                      "flight_rudder", "flight_flaps", "engine_throttle", "current-engine_throttle", "switches_master-avionics", "switches_starter",
                      "active-engine_auto-start", "flight_speedbrake", "c172p_brake-parking", "engine_primer", "current-engine_mixture",
                      "switches_master-bat", "switches_master-alt", "engine_rpm"};

  for (int i = 0; i < SIMULATOR_VARS_AMOUNT; ++i)
    // Add all the variables declared in the simulator to a map used by the manager.
    this->simulatorToProgramWrapping.insert({names[i], new list<string>});
}

MapsContainer::MapsContainer(Container *container) {
  createCommandsMap(container);
  createSimulatorToProgramWrappingMap();
}

SimulatorVar *MapsContainer::ReadVar(string key) {
  // We want to prevent only writers from changing our map. Readers are accepted.
  this->writers_lock.lock();

  SimulatorVar *returnValue = this->vars[key];

  this->writers_lock.unlock();
  return returnValue;
}

void MapsContainer::WriteVar(string key, double value) {
  // Nobody should access the map when we edit it.
  this->readers_lock.lock();
  this->writers_lock.lock();

  this->vars[key]->SetValue(value);

  this->writers_lock.unlock();
  this->readers_lock.unlock();
}

bool MapsContainer::InVars(string index) {
  // We want to prevent only writers from changing our map. Readers are accepted.
  this->writers_lock.lock();

  bool inVars = this->vars.count(index);

  this->writers_lock.unlock();
  return inVars;
}

void MapsContainer::AddVar(string key, SimulatorVar *value) {
  // Nobody should access the map when we edit it.
  this->readers_lock.lock();
  this->writers_lock.lock();

  this->vars.insert({key, value});

  this->writers_lock.unlock();
  this->readers_lock.unlock();
}

void MapsContainer::AddCommand(string key, Command *value) {
  // Nobody should access the map when we edit it.
  this->readers_lock.lock();
  this->writers_lock.lock();

  this->commands.insert({key, value});

  this->writers_lock.unlock();
  this->readers_lock.unlock();
}

void MapsContainer::AddWrappedVar(string simVar, string progVar) {
  // Nobody should access the map when we edit it.
  this->readers_lock.lock();
  this->writers_lock.lock();

  simulatorToProgramWrapping.at(simVar)->push_back(progVar);

  this->writers_lock.unlock();
  this->readers_lock.unlock();
}

void MapsContainer::WriteWrappedVar(string simVar, float value) {
  auto it = this->simulatorToProgramWrapping[simVar]->begin();

  while (it != this->simulatorToProgramWrapping[simVar]->end()) {
    this->WriteVar(*it, value);
    ++it;
  }
}