//
// Created by yoav on 25/12/2019.
//

#ifndef EX3_COMMANDS_VARCOMMANDS_BLOCKCOMMAND_H_
#define EX3_COMMANDS_VARCOMMANDS_BLOCKCOMMAND_H_

#include "Command.h"

class BlockCommand : Command {
 public:
  void executeBlock(vector<string> &commands, int index, Container& container);
  bool parseCondition(vector<string> &commands, int index, Container& container);
};

#endif //EX3_COMMANDS_VARCOMMANDS_BLOCKCOMMAND_H_
