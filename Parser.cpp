//
// Created by yoav on 21/12/2019.
//

#include "Parser.h"
#include "Commands/BlockCommands/FunctionCommand.h"
#include "InterpreterFiles/Interpreter.h"

Parser::Parser() {}

void Parser::parse(vector<string> *commands, Container *container) {
  int index = 0;
  while (index < commands->size()) { //while there are strings to read:
    //if this word is in the commands map
    //if the word is var, call the command that is the sign of the var declaration: = or -> or <-
    if (commands->at(index).compare(VAR_KEYWORD) == 0) {
      Command *c = container->GetMaps()->ReadCommand(commands->at(index + DISTANCE_TO_VAR_DECLARATION_SIGN));
      index += c->execute(*commands, index);
    } else if (container->GetMaps()->IsACommand(commands->at(index))) {
      //just run the command/function call
      Command *c = container->GetMaps()->ReadCommand(commands->at(index));
      index += c->execute(*commands, index);
    } else if (commands->at(index + 1).compare("var") == 0) {
      //current word is not in the commands map and the next word is "var", this is a function declaration
      container->GetMaps()->AddCommand(commands->at(index), new FunctionCommand(container, index));
      /*
       * i wanted to make a loop that increments "index" until found a "}" and then we know
       * the function declaration block is finished, but there might be a block in the function (e.g. while block)
       * so i used a smarter approach: i have a var that keeps the number of
       * opening braces minus number of closing braces we have seen since the function declaration.
       * when it gets the value 0, i know that the function is done.
       */
      int openingMinusClosingBraces = 1;//1 for the opening of the function
      index += DISTANCE_TO_BLOCK_START_AT_DECLARATION;
      //now move to the next command, after the function declaration
      while (openingMinusClosingBraces != 0) {
        if (commands->at(index).compare("{") == 0) {
          openingMinusClosingBraces++;
        } else if (commands->at(index).compare("}") == 0) {
          openingMinusClosingBraces--;
        }
        index++;
      }
      //now it has stopped because it has seen }, decremented the var,and incremented the index to be the next one.
    } else if (container->GetMaps()->InVars(commands->at(index))) {
      //should be a var name, so call the change var value command
      Command *c = container->GetMaps()->ReadCommand(NEW_VALUE_COMMAND);
      index += c->execute(*commands, index);
    } else {//error or something we did not think about
      string message(commands->at(index) + " is not a command");
      throw message.c_str();
    }
  }
}

