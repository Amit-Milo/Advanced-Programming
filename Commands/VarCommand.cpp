//
// Created by yoav on 22/12/2019.
//

#include "VarCommand.h"
#include "../Containers/Container.h"

VarCommand::VarCommand(Container *container) : Command(container) {}

void VarCommand::arrowCommand(vector<string> &params, int start, Wrapping wrapping) {
  string progVarName = params.at(start + DISTANCE_TO_PROG_VAR_NAME_ARROW_COMMAND);
  string simVarName = params.at(start + DISTANCE_TO_SIM_VAR_NAME_ARROW_COMMAND);

  SimulatorVar *value = new SimulatorVar(progVarName, simVarName, wrapping);

  container->maps->AddVar(progVarName, value);
}
