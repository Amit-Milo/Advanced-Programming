//
// Created by yoav on 25/12/2019.
//


#include "BlockCommand.h"

#include "../Containers/Container.h"
#include "../InterpreterFiles/Interpreter.h"

///////////////////////////////////////////this is a copy of Parser::parse. change if changed
void BlockCommand::executeBlock(vector<string> &commands, int index) {
  while (index < commands.size() && commands.at(index).compare("}") != 0) { //while there are strings to read:
    //if this word is in the commands map
    if (container->maps->commands.count(commands.at(index)) != 0) {
      //if the word is var, call the command that is the sign of the var declaration: = or -> or <-
      if (commands.at(index).compare(VAR_KEYWORD) == 0) {
        Command *c = container->maps->commands.at(commands.at(index + 2));
        index += c->execute(commands, index);
      } else { //just run the command
        Command *c = container->maps->commands.at(commands.at(index));
        index += c->execute(commands, index);
      }
    } else if (container->maps->InVars(commands.at(index))) {
      //should be a var name, so call the change var value command
      Command *c = container->maps->commands.at(NEW_VALUE_COMMAND);
      index += c->execute(commands, index);
    } else { //error or something we did not think about
      string message(commands.at(index) + " is not a command");
      throw message.c_str();
    }
  }
}

bool BlockCommand::parseCondition(vector<string> &commands, int index) {
  //evaluate the sides of the condition
  double left = container->interpreter->evaluate(commands.at(index + 1));
  double right = container->interpreter->evaluate(commands.at(index + 3));
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

BlockCommand::BlockCommand(Container *container) : Command(container) {}

int BlockCommand::returnJump(vector<string> &commands, int start) {
  int curr = start;
  //get to the index of "}"
  while (commands.at(curr).compare("}") != 0) {
    curr++;
  }
  //now it is at "}". return the distance on the vector from start to current place
  return curr - start + 1;
}

int BlockCommand::blockStartIndex(vector<string> &commands, int start) {
  int insideBlockIndex = start;
  while (commands.at(insideBlockIndex).compare("{") != 0) {
    insideBlockIndex++;
  }
  insideBlockIndex++;//now insideBlockIndex is at first command inside the block
  return insideBlockIndex;
}
