//
// Created by yoav on 04/01/2020.
//

#include "ArrowVarCommand.h"
#include "../../Containers/Container.h"
#include "../../Containers/MapsContainer.h"

ArrowVarCommand::ArrowVarCommand(Container *container) : VarCommand(container) {}

void ArrowVarCommand::arrowCommand(vector<string> &params, int start, Wrapping wrapping) {
  string progVarName = params.at(start + DISTANCE_TO_PROG_VAR_NAME_ARROW_COMMAND);
  string simVarName = params.at(start + DISTANCE_TO_SIM_VAR_NAME_ARROW_COMMAND);

  //a simulator var with a wrapping.
  SimulatorVar *value = new SimulatorVar(progVarName, simVarName, wrapping, container);

  container->maps->AddVar(progVarName, value);
}

