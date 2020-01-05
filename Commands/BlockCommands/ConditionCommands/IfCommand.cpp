//
// Created by yoav on 25/12/2019.
//

#include "IfCommand.h"

int IfCommand::execute(vector<string> &params, int start) {
  //if condition is true, execute the if block.
  if (parseCondition(params, start)) {
    executeBlock(params, blockStartIndex(params, start));
  }
  return returnJump(params, start);
}
IfCommand::IfCommand(Container *container) : BlockCommand(container) {}
