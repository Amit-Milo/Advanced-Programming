//
// Created by yoav on 23/12/2019.
//

#include "ChangeValueCommand.h"
#include "../../Containers/Container.h"
#include "../../Containers/MapsContainer.h"
#include "../../InterpreterFiles/Interpreter.h"

#define RETURN_VALUE 3

int ChangeValueCommand::execute(vector<string> &params, int start) {
  //get the new var value
  double newVal = container->interpreter->evaluate(params.at(start+DISTANCE_TO_NEW_VAL));
  //set the new value
  container->maps->WriteVar(params.at(start),newVal);
  return RETURN_VALUE;
}
ChangeValueCommand::ChangeValueCommand(Container *container) : VarCommand(container) {}
