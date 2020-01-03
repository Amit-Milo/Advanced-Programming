//
// Created by yoav on 25/12/2019.
//

#include "WhileCommand.h"
int WhileCommand::execute(vector<string> &params, int start) {
  int insideBlockIndex = start;
  while (params.at(insideBlockIndex).compare("{") != 0) {
    insideBlockIndex++;
  }
  insideBlockIndex++;//now insideBlockIndex is at first command inside the block

  while (parseCondition(params, start)) {
    executeBlock(params, insideBlockIndex);
  }

  return returnJump(params,start);
}

WhileCommand::WhileCommand(Container *container) : BlockCommand(container) {}
