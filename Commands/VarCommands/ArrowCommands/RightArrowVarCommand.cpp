//
// Created by yoav on 23/12/2019.
//

#include "RightArrowVarCommand.h"

#define RETURN_VALUE 5

int RightArrowVarCommand::execute(vector<string> &params, int start) {
  //call the arrow command from VarCommand
  arrowCommand(params, start, PROG_TO_SIM);
  return RETURN_VALUE;
}

RightArrowVarCommand::RightArrowVarCommand(Container *container) : ArrowVarCommand(container) {}
