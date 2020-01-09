//
// Created by yoav on 05/01/2020.
//

#include "ConditionBlock.h"
#include "../../Containers/Container.h"
#include "../../InterpreterFiles/Interpreter.h"


bool ConditionBlock::parseCondition(vector<string> &commands, int index) {
  //evaluate the sides of the condition
  double left = container->GetInterpreter()->evaluate(commands.at(index + 1));
  double right = container->GetInterpreter()->evaluate(commands.at(index + 3));
  //now check the condition and return accordingly:
  string condition = commands.at(index + 2);
  if (condition.compare("==") == 0) {
    return left == right;
  } else if (condition.compare("!=") == 0) {
    return left != right;
  } else if (condition.compare("<=") == 0) {
    return left <= right;
  } else if (condition.compare(">=") == 0) {
    return left >= right;
  } else if (condition.compare("<") == 0) {
    return left < right;
  } else if (condition.compare(">") == 0) {
    return left > right;
  } else {
    string err("error with conditions, expected condition but got: " + condition);
    throw err.c_str();
  }
}
ConditionBlock::ConditionBlock(Container *container) : BlockCommand(container) {}
