//
// Created by yoav on 25/12/2019.
//

#include "WhileCommand.h"
int WhileCommand::execute(vector<string> &params, int start) {
  int insideBlockIndex = blockStartIndex(params, start);
  //while condition is true, execute the while block.
  while (parseCondition(params, start)) {
    executeBlock(params, insideBlockIndex);
  }

  return returnJump(params, start);
}

WhileCommand::WhileCommand(Container *container) : BlockCommand(container) {}
