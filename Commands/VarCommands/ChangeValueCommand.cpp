//
// Created by yoav on 23/12/2019.
//

#include "ChangeValueCommand.h"

int ChangeValueCommand::execute() {
  return JUMP_VAl;
}
ChangeValueCommand::ChangeValueCommand(unordered_map<string, SimulatorVar *> *prog_vars,
                                       unordered_map<string, SimulatorVar *> *simulator_vars) : VarCommand(prog_vars,
                                                                                                           simulator_vars) {}
