//
// Created by yoav on 23/12/2019.
//

#ifndef EX3_COMMANDS_CHANGEVALUECOMMAND_H_
#define EX3_COMMANDS_CHANGEVALUECOMMAND_H_

#include "../VarCommand.h"

class ChangeValueCommand:public VarCommand{
 public:
  int execute() override;
  ChangeValueCommand(unordered_map<string, SimulatorVar *> *prog_vars,
                     unordered_map<string, SimulatorVar *> *simulator_vars);
};

#endif //EX3_COMMANDS_CHANGEVALUECOMMAND_H_
