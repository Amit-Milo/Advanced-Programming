//
// Created by yoav on 04/01/2020.
//

#include <unistd.h>
#include "SleepCommand.h"
#include "../Containers/Container.h"
#include "../InterpreterFiles/Interpreter.h"


#define RETURN_VALUE 2

int SleepCommand::execute(vector<string> &params, int start) {
  int time = (int)(container->GetInterpreter()->evaluate(params.at(start+DIStANCE_TO_SLEEP_VALUE)))*1000;
  usleep(time);
  return RETURN_VALUE;
}

SleepCommand::SleepCommand(Container *container) : Command(container) {}
