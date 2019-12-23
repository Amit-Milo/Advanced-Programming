//
// Created by yoav on 23/12/2019.
//

#include "RightArrowVarCommand.h"

int RightArrowVarCommand::execute() {
  return 0;
}
RightArrowVarCommand::RightArrowVarCommand(unordered_map<string, SimulatorVar *> *prog_vars,
                                           unordered_map<string, SimulatorVar *> *simulator_vars)
    : VarCommand(prog_vars, simulator_vars) {}
