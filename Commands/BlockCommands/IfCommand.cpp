//
// Created by yoav on 25/12/2019.
//

#include "IfCommand.h"

int IfCommand::execute(vector<string> &params, int start) {
  if (parseCondition(params, start)) {

    while (params.at(start).compare("{") != 0) {
      start++;
    }
    start++;//now start is at first command inside the block

    executeBlock(params, start);
  }
}
IfCommand::IfCommand(Container *container) : BlockCommand(container) {}
