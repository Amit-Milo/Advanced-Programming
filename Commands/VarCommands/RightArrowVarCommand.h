//
// Created by yoav on 23/12/2019.
//

#ifndef EX3_COMMANDS_RIGHTARROWVARCOMMAND_H_
#define EX3_COMMANDS_RIGHTARROWVARCOMMAND_H_

#include "../VarCommand.h"
#define JUMP_VAl 5

class RightArrowVarCommand : public VarCommand {
 public:
  int execute(vector<string> &params, int start) override;
  RightArrowVarCommand(Container *container);
};

#endif //EX3_COMMANDS_RIGHTARROWVARCOMMAND_H_
