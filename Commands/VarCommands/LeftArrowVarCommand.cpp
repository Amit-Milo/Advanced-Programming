//
// Created by yoav on 23/12/2019.
//

#include "LeftArrowVarCommand.h"
#include "../../Containers/Container.h"

#define RETURN_VALUE 5

int LeftArrowVarCommand::execute(vector<string> &params, int start) {
  arrowCommand(params, start, SIM_TO_PROG);
  container->maps->AddWrappedVar(params.at(start + DISTANCE_TO_SIM_VAR_NAME_ARROW_COMMAND),
                                 params.at(start + DISTANCE_TO_PROG_VAR_NAME_ARROW_COMMAND));
  return RETURN_VALUE;
}

LeftArrowVarCommand::LeftArrowVarCommand(Container *container) : VarCommand(container) {}
