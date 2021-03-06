//
// Created by yoav on 04/01/2020.
//

#include <iostream>
#include "PrintCommand.h"
#include "../Containers/Container.h"
#include "../InterpreterFiles/Interpreter.h"

#define RETURN_VALUE 2

int PrintCommand::execute(vector<string> &params, int start) {
  string msg = params.at(start + DISTANCE_TO_PRINTED_MESSAGE);
  //if printing a string:
  if (msg.at(0) == '\"' && msg.at(msg.length() - 1) == '\"') {
    std::cout << msg.substr(1, msg.length() - 2) << std::endl; //print the string without the " at the ends.
  } else { //i think that means that it is an Expression. print its value.
    std::cout << container->GetInterpreter()->evaluate(msg) << std::endl;
  }
  return RETURN_VALUE;
}

PrintCommand::PrintCommand(Container *container) : Command(container) {}
