//
// Created by yoav on 23/12/2019.
//

#ifndef EX3_COMMANDS_RIGHTARROWVARCOMMAND_H_
#define EX3_COMMANDS_RIGHTARROWVARCOMMAND_H_

#include "../VarCommand.h"

class RightArrowVarCommand : public VarCommand {
 public:
  int execute() override;
  RightArrowVarCommand(unordered_map<string, SimulatorVar *> *prog_vars,
                       unordered_map<string, SimulatorVar *> *simulator_vars);
};

#endif //EX3_COMMANDS_RIGHTARROWVARCOMMAND_H_
