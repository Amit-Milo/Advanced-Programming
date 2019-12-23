//
// Created by yoav on 23/12/2019.
//

#ifndef EX3_COMMANDS_VARCOMMANDS_LEFTARROWVARCOMMAND_H_
#define EX3_COMMANDS_VARCOMMANDS_LEFTARROWVARCOMMAND_H_

#include "../VarCommand.h"
#define JUMP_VAl 5

class LeftArrowVarCommand:public VarCommand{
 public:
  int execute() override;
  LeftArrowVarCommand(unordered_map<string, SimulatorVar *> *prog_vars,
                      unordered_map<string, SimulatorVar *> *simulator_vars);
};

#endif //EX3_COMMANDS_VARCOMMANDS_LEFTARROWVARCOMMAND_H_
