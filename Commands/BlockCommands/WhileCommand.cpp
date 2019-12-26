//
// Created by yoav on 25/12/2019.
//

#include "WhileCommand.h"
int WhileCommand::execute(vector<string> &params, int start, Container &container) {
  int insideBlockIndex = start;
  while (params.at(insideBlockIndex).compare("{") != 0) {
    insideBlockIndex++;
  }
  insideBlockIndex++;//now insideBlockIndex is at first command inside the block

  while (parseCondition(params, start, container)) {
    executeBlock(params, insideBlockIndex, container);
  }
}
