//
// Created by yoav on 05/01/2020.
//

#ifndef EX3_COMMANDS_BLOCKCOMMANDS_CONDITIONBLOCK_H_
#define EX3_COMMANDS_BLOCKCOMMANDS_CONDITIONBLOCK_H_

#include "../BlockCommand.h"

class ConditionBlock: public BlockCommand{
 public:
  /**
   * parse the condition of the block and return the result
   * @param commands vector of commands.
   * @param index the index of the while/if word.
   * @return true/false according to the condition.
   */
  bool parseCondition(vector<string> &commands, int index);
  ConditionBlock(Container *container);
};

#endif //EX3_COMMANDS_BLOCKCOMMANDS_CONDITIONBLOCK_H_
