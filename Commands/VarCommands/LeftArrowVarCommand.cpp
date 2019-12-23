//
// Created by yoav on 23/12/2019.
//

#include "LeftArrowVarCommand.h"

int LeftArrowVarCommand::execute() {
  return 0;
}
LeftArrowVarCommand::LeftArrowVarCommand(unordered_map<string, SimulatorVar *> *prog_vars,
                                         unordered_map<string, SimulatorVar *> *simulator_vars) : VarCommand(prog_vars,
                                                                                                             simulator_vars) {}
