//
// Created by yoav on 21/12/2019.
//

#include "Parser.h"

#define NEW_VALUE_COMMAND "newValueCommand"
#define VAR_KEYWORD "var"

Parser::Parser() {
  setCommandsMap();
}

void Parser::setCommandsMap() {
  commandsMap.insert({"openDataServer", pair<Command *, int>(new OpenDataServerCommand(), 2)});
  commandsMap.insert({"connectControlClient", pair<Command *, int>(new ConnectControlClientCommand(), 3)});
  commandsMap.insert({"=", pair<Command *, int>(new EqualSignVarCommand(&progVars, &simulatorVars), 4)});
  commandsMap.insert({"->", pair<Command *, int>(new RightArrowVarCommand(&progVars, &simulatorVars), 5)});
  commandsMap.insert({"<-", pair<Command *, int>(new LeftArrowVarCommand(&progVars, &simulatorVars), 5)});
  commandsMap.insert({NEW_VALUE_COMMAND, pair<Command *, int>(new ChangeValueCommand(&progVars, &simulatorVars), 3)});
}

void Parser::parse(vector<string> *commands) {
  int index = 0;
  while (index < commands->size()) {
    if (commandsMap.count(commands->at(index)) != 0) {
      if (commands->at(index).compare(VAR_KEYWORD) == 0) {
        string comm = commands->at(index + 2);
        Command *c = commandsMap.at(comm).first;
        c->execute();
        index += commandsMap.at(comm).second;
      } else {
        Command *c = commandsMap.at(commands->at(index)).first;
        c->execute();
        index += commandsMap.at(commands->at(index)).second;
      }
    } else if (progVars.count(commands->at(index)) != 0) { //should be a var name
      Command *c = commandsMap.at(NEW_VALUE_COMMAND).first;
      c->execute();
      index += commandsMap.at(NEW_VALUE_COMMAND).second;
    } else { //error or something we did not think about
      string message(commands->at(index) + " is not a command");
      throw message.c_str();
    }
  }
}

