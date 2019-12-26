//
// Created by yoav on 25/12/2019.
//

#ifndef EX3_COMMANDS_BLOCKCOMMANDS_WHILECOMMAND_H_
#define EX3_COMMANDS_BLOCKCOMMANDS_WHILECOMMAND_H_

#include "../BlockCommand.h"
#include "../Command.h"
#include <list>

class WhileCommand : public BlockCommand {
  int execute(vector<string> &params, int start, Container &container) override;

};

#endif //EX3_COMMANDS_BLOCKCOMMANDS_WHILECOMMAND_H_
