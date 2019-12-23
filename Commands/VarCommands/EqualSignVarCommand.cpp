//
// Created by yoav on 23/12/2019.
//

#include "EqualSignVarCommand.h"

int EqualSignVarCommand::execute() {
  return JUMP_VAl;
}
EqualSignVarCommand::EqualSignVarCommand(unordered_map<string, SimulatorVar *> *prog_vars,
                                         unordered_map<string, SimulatorVar *> *simulator_vars) : VarCommand(prog_vars,
                                                                                                             simulator_vars) {}
