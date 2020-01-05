//
// Created by amit on 01/01/2020.
//

#include "MapsContainer.h"

#include "../Commands/ConnectControlClientCommand.h"
#include "../Commands/OpenDataServerCommand.h"
#include "../Commands/SleepCommand.h"
#include "../Commands/PrintCommand.h"
#include "../Commands/BlockCommands/ConditionCommands/WhileCommand.h"
#include "../Commands/BlockCommands/ConditionCommands/IfCommand.h"
#include "../Commands/VarCommands/ChangeValueCommand.h"
#include "../Commands/VarCommands/EqualSignVarCommand.h"
#include "../Commands/VarCommands/ArrowCommands/RightArrowVarCommand.h"
#include "../Commands/VarCommands/ArrowCommands/LeftArrowVarCommand.h"
#include "../Parser.h"

void MapsContainer::createCommandsMap(Container *container) {
  // Nobody should access the map when we edit it.
  this->commands_readers_lock.lock();
  this->commands_writers_lock.lock();

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

  this->commands_writers_lock.unlock();
  this->commands_readers_lock.unlock();
}

void MapsContainer::createSimulatorToProgramWrappingMap() {
  // Nobody should access the map when we edit it.
  this->simulator_readers_lock.lock();
  this->simulator_writers_lock.lock();

  for (int i = 0; i < SIMULATOR_VARS_AMOUNT; ++i)
    // Add all the variables declared in the simulator to a map used by the manager.
    this->simulatorToProgramWrapping.insert({MapsContainer::names[i], new list<string>});

  this->simulator_writers_lock.unlock();
  this->simulator_readers_lock.unlock();
}

MapsContainer::MapsContainer(Container *container) {
  createCommandsMap(container);
  createSimulatorToProgramWrappingMap();
}

SimulatorVar *MapsContainer::ReadVar(string key) {
  // We want to prevent only writers from changing our map. Readers are accepted.
  this->vars_writers_lock.lock();

  SimulatorVar *returnValue = this->vars[key];

  this->vars_writers_lock.unlock();
  return returnValue;
}

void MapsContainer::WriteVar(string key, double value) {
  // Nobody should access the map when we edit it.
  this->vars_readers_lock.lock();
  this->vars_writers_lock.lock();

  this->vars[key]->SetValue(value);

  this->vars_writers_lock.unlock();
  this->vars_readers_lock.unlock();
}

bool MapsContainer::InVars(string index) {
  // We want to prevent only writers from changing our map. Readers are accepted.
  this->vars_writers_lock.lock();

  bool inVars = this->vars.count(index);

  this->vars_writers_lock.unlock();
  return inVars;
}

void MapsContainer::AddVar(string key, SimulatorVar *value) {
  // Nobody should access the map when we edit it.
  this->vars_readers_lock.lock();
  this->vars_writers_lock.lock();

  this->vars.insert({key, value});

  this->vars_writers_lock.unlock();
  this->vars_readers_lock.unlock();
}

void MapsContainer::AddCommand(string key, Command *value) {
  // Nobody should access the map when we edit it.
  this->commands_readers_lock.lock();
  this->commands_writers_lock.lock();

  this->commands.insert({key, value});

  this->commands_writers_lock.unlock();
  this->commands_readers_lock.unlock();
}

void MapsContainer::AddWrappedVar(string simVar, string progVar) {
  // Nobody should access the map when we edit it.
  this->simulator_readers_lock.lock();
  this->simulator_writers_lock.lock();

  // Add the new variable wrapped by the simulator to a list of variables which should be updated when simulator changes value.
  // Observer design pattern.
  simulatorToProgramWrapping.at(simVar)->push_back(progVar);

  this->simulator_writers_lock.unlock();
  this->simulator_readers_lock.unlock();
}

void MapsContainer::WriteWrappedVar(string simVar, float value) {
  auto it = this->simulatorToProgramWrapping[simVar]->begin();

  while (it != this->simulatorToProgramWrapping[simVar]->end()) {
    this->WriteVar(*it, value);
    ++it;
  }
}