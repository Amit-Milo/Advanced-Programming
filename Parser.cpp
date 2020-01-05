//
// Created by yoav on 21/12/2019.
//

#include "Parser.h"
#include "Commands/BlockCommands/FunctionCommand.h"

Parser::Parser() {}

void Parser::parse(vector<string> *commands, Container *container) {
  int index = 0;
  while (index < commands->size()) { //while there are strings to read:
    //if this word is in the commands map
    //if the word is var, call the command that is the sign of the var declaration: = or -> or <-
    if (commands->at(index).compare(VAR_KEYWORD) == 0) {
      Command *c = container->maps->commands.at(commands->at(index + DISTANCE_TO_VAR_DECLARATION_SIGN));
      index += c->execute(*commands, index);
    } else if (container->maps->commands.count(commands->at(index)) != 0) {
      //just run the command
      Command *c = container->maps->commands.at(commands->at(index));
      index += c->execute(*commands, index);
    } else if (commands->at(index + 1).compare("var") == 0) {
      //current word is not in the commands map and the next word is "var", this is a function declaration
      container->maps->AddCommand(commands->at(index), new FunctionCommand(container, index));
    } else if (container->maps->InVars(commands->at(index))) {
      //should be a var name, so call the change var value command
      Command *c = container->maps->commands.at(NEW_VALUE_COMMAND);
      index += c->execute(*commands, index);
    } else {//error or something we did not think about
      string message(commands->at(index) + " is not a command");
      throw message.c_str();
    }
  }
}

