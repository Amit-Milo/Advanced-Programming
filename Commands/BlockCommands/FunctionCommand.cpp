//
// Created by yoav on 05/01/2020.
//

#include "FunctionCommand.h"
#include "../../Containers/Container.h"
#include "../../Containers/MapsContainer.h"

int FunctionCommand::execute(vector<string> &params, int start) {
  //get the input value to the var
  double inputVarValue = stod(params.at(start + DISTANCE_TO_INPUT_VAR_VALUE));
  //add the declared var to the map and remember its name
  string inputVarName = params.at(funcStartInLexer + DISTANCE_TO_NAME_OF_DECLARED_VAR);
  container->maps->AddVar(inputVarName, new SimulatorVar(inputVarValue, inputVarName, container));
  //call the execution of the function, go to the line it was declared and execute it until it is done.
  executeBlock(params, blockStartIndex(params, funcStartInLexer));
  //now we finished running the function, remove the new var from the map.
  container->maps->DeleteVar(inputVarName);
  return RETURN_VALUE_FROM_FUNCTION_CALL;
}

FunctionCommand::FunctionCommand(Container *container, int func_start_in_lexer)
    : BlockCommand(container), funcStartInLexer(func_start_in_lexer) {}
