//
// Created by yoav on 25/12/2019.
//


#include "BlockCommand.h"

//////////////////////////////////////////////////////////////////maybe handle scope vars

///////////////////////////////////////////this is a copy of Parser::parse. change if changed
void BlockCommand::executeBlock(vector<string> &commands, int index, Container &container) {
  while (index < commands.size() && commands.at(index).compare("}") != 0) {
    if (container.maps.commandsMap.count(commands.at(index)) != 0) {
      if (commands.at(index).compare(VAR_KEYWORD) == 0) {
        Command *c = container.maps.commandsMap.at(commands.at(index + 2));
        index += c->execute(commands, index, container);
      } else {
        Command *c = container.maps.commandsMap.at(commands.at(index));
        index += c->execute(commands, index, container);
      }
    } else if (container.maps.progVars.count(commands.at(index)) != 0) { //should be a var name
      Command *c = container.maps.commandsMap.at(NEW_VALUE_COMMAND);
      index += c->execute(commands, index, container);
    } else { //error or something we did not think about
      string message(commands.at(index) + " is not a command");
      throw message.c_str();
    }
  }
}

bool BlockCommand::parseCondition(vector<string> &commands, int index, Container &container) {
  double left = container.interpreter.evaluate(commands.at(index + 1));
  double right = container.interpreter.evaluate(commands.at(index + 3));
  //now check the condition:
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
