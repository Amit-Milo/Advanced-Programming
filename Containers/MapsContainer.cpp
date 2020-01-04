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

#define SHOULD_CHANGE_ERROR_AMIT -2

void MapsContainer::createCommandsMap(Container *container) {
  this->AddCommand("openDataServer", new OpenDataServerCommand(container, SHOULD_CHANGE_ERROR_AMIT));
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
  //TODO amit hard-code the xml vars
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
  //TODO amit add mutex
  this->vars.insert({key, value});
}

void MapsContainer::AddCommand(string key, Command *value) {
  //TODO amit add mutex
  this->commands.insert({key, value});
}

void MapsContainer::AddWrappedVar(string simVar, string progVar) {
  //TODO amit add mutex
  simulatorToProgramWrapping.at(simVar).push_back(progVar);
}
