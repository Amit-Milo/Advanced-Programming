//
// Created by yoav on 25/12/2019.
//

#ifndef EX3_COMMANDS_VARCOMMANDS_BLOCKCOMMAND_H_
#define EX3_COMMANDS_VARCOMMANDS_BLOCKCOMMAND_H_

#include "Command.h"
#define NEW_VALUE_COMMAND string("newValueCommand")
#define VAR_KEYWORD string("var")

class Container;

class BlockCommand : public Command {
 public:
  void executeBlock(vector<string> &commands, int index);
  bool parseCondition(vector<string> &commands, int index);
  BlockCommand(Container *container);
};

#endif //EX3_COMMANDS_VARCOMMANDS_BLOCKCOMMAND_H_
