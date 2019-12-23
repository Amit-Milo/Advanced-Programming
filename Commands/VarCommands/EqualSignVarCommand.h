//
// Created by yoav on 23/12/2019.
//

#ifndef EX3_COMMANDS_VARCOMMANDS_EQUALSIGNVARCOMMAND_H_
#define EX3_COMMANDS_VARCOMMANDS_EQUALSIGNVARCOMMAND_H_

#include "../VarCommand.h"
#define JUMP_VAl 4

class EqualSignVarCommand:public VarCommand{
 public:
  int execute() override;
  EqualSignVarCommand(unordered_map<string, SimulatorVar *> *prog_vars,
                      unordered_map<string, SimulatorVar *> *simulator_vars);
};

#endif //EX3_COMMANDS_VARCOMMANDS_EQUALSIGNVARCOMMAND_H_
