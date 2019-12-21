//
// Created by yoav on 21/12/2019.
//

#include "Parser.h"
#include "Commands/Command.h"
#include "Commands/OpenDataServerCommand.h"

Parser::Parser() {
  setCommandsMap();
}

void Parser::setCommandsMap() {
  commandsMap.insert({"openDataServer", OpenDataServerCommand()});
}

void Parser::parse(vector<string> *commands) {
  int index = 0;
  while (index < commands->size()) {
    if (commandsMap.count(commands->at(index))==0){
      string message(commands->at(index)+" is not a command");
      throw message.c_str();
    }
    Command c = commandsMap.at(commands->at(index));

    index+= c.execute();

  }

}

