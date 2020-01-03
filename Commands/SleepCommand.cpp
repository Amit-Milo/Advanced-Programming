//
// Created by yoav on 04/01/2020.
//

#include "SleepCommand.h"

#define RETURN_VALUE 2

int SleepCommand::execute(vector<string> &params, int start) {
  // TODO sleep thread/s
  return RETURN_VALUE;
}

SleepCommand::SleepCommand(Container *container) : Command(container) {}
