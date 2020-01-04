//
// Created by yoav on 23/12/2019.
//

#include "ChangeValueCommand.h"
#include "../../Containers/Container.h"
#define RETURN_VALUE 3

int ChangeValueCommand::execute(vector<string> &params, int start) {
  double newVal = stod(params.at(start+DISTANCE_TO_NEW_VAL));
  container->maps->ChangeVar(params.at(start),newVal);
  return RETURN_VALUE;
}
ChangeValueCommand::ChangeValueCommand(Container *container) : VarCommand(container) {}
