//
// Created by yoav on 23/12/2019.
//

#include "EqualSignVarCommand.h"
#include "../../Containers/Container.h"
#include "../../InterpreterFiles/Interpreter.h"
#define RETURN_VALUE 4

int EqualSignVarCommand::execute(vector<string> &params, int start) {
  string varName = params.at(start + DISTANCE_TO_VAR_NAME);
  double value = container->GetInterpreter()->evaluate(params.at(start + DISTANCE_TO_VALUE));
  //wrapping is not transitive, so if i get a value which is a name of a var, it is still a NONE wrapping var
  container->GetMaps()->AddVar(varName, new SimulatorVar(value, varName, container));
  return RETURN_VALUE;
}
EqualSignVarCommand::EqualSignVarCommand(Container *container) : VarCommand(container) {}
