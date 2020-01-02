//
// Created by yoav on 25/12/2019.
//

#ifndef EX3_COMMANDS_BLOCKCOMMANDS_IFCOMMAND_H_
#define EX3_COMMANDS_BLOCKCOMMANDS_IFCOMMAND_H_

#include "../BlockCommand.h"

class IfCommand:public BlockCommand{
  int execute(vector<string> &params, int start) override;
 public:
  IfCommand(Container *container);
};

#endif //EX3_COMMANDS_BLOCKCOMMANDS_IFCOMMAND_H_
