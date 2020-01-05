//
// Created by yoav on 25/12/2019.
//

#ifndef EX3_COMMANDS_BLOCKCOMMANDS_IFCOMMAND_H_
#define EX3_COMMANDS_BLOCKCOMMANDS_IFCOMMAND_H_

#include "../ConditionBlock.h"

class IfCommand : public ConditionBlock {
  int execute(vector<string> &params, int start) override;
 public:
  IfCommand(Container *container);
};

#endif //EX3_COMMANDS_BLOCKCOMMANDS_IFCOMMAND_H_
