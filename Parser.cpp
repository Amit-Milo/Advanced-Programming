//
// Created by yoav on 21/12/2019.
//

#include "Parser.h"

#define NEW_VALUE_COMMAND string("newValueCommand")
#define VAR_KEYWORD string("var")

Parser::Parser() {
  setCommandsMap();
}

void Parser::setCommandsMap() {
  commandsMap.insert({"openDataServer", new OpenDataServerCommand()});
  commandsMap.insert({"connectControlClient", new ConnectControlClientCommand()});
  commandsMap.insert({"=", new EqualSignVarCommand(&progVars, &simulatorVars)});
  commandsMap.insert({"->", new RightArrowVarCommand(&progVars, &simulatorVars)});
  commandsMap.insert({"<-", new LeftArrowVarCommand(&progVars, &simulatorVars)});
  commandsMap.insert({NEW_VALUE_COMMAND, new ChangeValueCommand(&progVars, &simulatorVars)});
  //while
  //if
}

void Parser::parse(vector<string> *commands) {
  int index = 0;
  while (index < commands->size()) {
    if (commandsMap.count(commands->at(index)) != 0) {
      if (commands->at(index).compare(VAR_KEYWORD) == 0) {
        Command *c = commandsMap.at(commands->at(index + 2));
        index += c->execute();
      } else {
        Command *c = commandsMap.at(commands->at(index));
        index += c->execute();
      }
    } else if (progVars.count(commands->at(index)) != 0) { //should be a var name
      Command *c = commandsMap.at(NEW_VALUE_COMMAND);
      index += c->execute();
    } else { //error or something we did not think about
      string message(commands->at(index) + " is not a command");
      throw message.c_str();
    }
  }
}

