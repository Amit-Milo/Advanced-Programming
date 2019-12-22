//
// Created by yoav on 22/12/2019.
//

#include "VarCommand.h"

VarCommand::VarCommand(unordered_map<string, SimulatorVar*> *prog_vars,
                       unordered_map<string, SimulatorVar*> *simulator_vars)
    : progVars(prog_vars), simulatorVars(simulator_vars) {}

int VarCommand::execute() {
  return 0;
}