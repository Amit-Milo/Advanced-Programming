//
// Created by yoav on 21/12/2019.
//

#include "Parser.h"

Parser::Parser() {}

///////////////////////////////////////////this has a copy in BlockCommand::executeBlock. change if changed
void Parser::parse(vector<string> *commands, Container &container) {
  int index = 0;
  while (index < commands->size()) {
    if (container.maps.commandsMap.count(commands->at(index)) != 0) {
      if (commands->at(index).compare(VAR_KEYWORD) == 0) {
        Command *c = container.maps.commandsMap.at(commands->at(index + 2));
        index += c->execute(*commands, index, container);
      } else {
        Command *c = container.maps.commandsMap.at(commands->at(index));
        index += c->execute(*commands, index, container);
      }
    } else if (container.maps.inVars(commands->at(index))) { //should be a var name
      Command *c = container.maps.commandsMap.at(NEW_VALUE_COMMAND);
      index += c->execute(*commands, index, container);
    } else { //error or something we did not think about
      string message(commands->at(index) + " is not a command");
      throw message.c_str();
    }
  }
}

