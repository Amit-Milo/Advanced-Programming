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
  /**
   * execute the block of this command
   * @param commands the commands vector
   * @param index the first index of the block
   */
  void executeBlock(vector<string> &commands, int index);
  /**
   * parse the condition of the block and return the result
   * @param commands vector of commands.
   * @param index the index of the while/if word.
   * @return true/false according to the condition.
   */
  bool parseCondition(vector<string> &commands, int index);
  /**
   * @return number to jump to next command after this block.
   */
  int returnJump(vector<string> &commands, int start);
  /**
   * @return index of start of the block.
   */
  int blockStartIndex(vector<string> &commands, int start);
  BlockCommand(Container *container);
};

#endif //EX3_COMMANDS_VARCOMMANDS_BLOCKCOMMAND_H_
