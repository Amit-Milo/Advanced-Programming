//
// Created by yoav on 23/12/2019.
//

#include "LeftArrowVarCommand.h"

#define RETURN_VALUE 5

int LeftArrowVarCommand::execute(vector<string> &params, int start) {
  arrowCommand(params, start, SIM_TO_PROG);
  return RETURN_VALUE;
}

LeftArrowVarCommand::LeftArrowVarCommand(Container *container) : VarCommand(container) {}
