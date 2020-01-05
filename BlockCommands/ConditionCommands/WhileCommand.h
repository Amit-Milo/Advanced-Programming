//
// Created by yoav on 25/12/2019.
//

#ifndef EX3_COMMANDS_BLOCKCOMMANDS_WHILECOMMAND_H_
#define EX3_COMMANDS_BLOCKCOMMANDS_WHILECOMMAND_H_

#include "../ConditionBlock.h"
#include "../../Command.h"
#include <list>

class WhileCommand : public ConditionBlock {
  int execute(vector<string> &params, int start) override;
 public:
  WhileCommand(Container *container);
};

#endif //EX3_COMMANDS_BLOCKCOMMANDS_WHILECOMMAND_H_
