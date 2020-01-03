//
// Created by yoav on 21/12/2019.
//

#include "Parser.h"

Parser::Parser() {}

///////////////////////////////////////////this has a copy in BlockCommand::executeBlock. change if changed
void Parser::parse(vector<string> *commands, Container *container) {
  int index = 0;
  while (index < commands->size()) {
    if (container->maps.commands.count(commands->at(index)) != 0) {
      if (commands->at(index).compare(VAR_KEYWORD) == 0) {
        Command *c = container->maps.commands.at(commands->at(index + 2));
        index += c->execute(*commands, index);
      } else {
        Command *c = container->maps.commands.at(commands->at(index));
        index += c->execute(*commands, index);
      }
    } else if (container->maps.InVars(commands->at(index))) { //should be a var name
      Command *c = container->maps.commands.at(NEW_VALUE_COMMAND);
      index += c->execute(*commands, index);
    } else { //error or something we did not think about
      string message(commands->at(index) + " is not a command");
      throw message.c_str();
    }
  }
}

