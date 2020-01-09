//
// Created by yoav on 25/12/2019.
//


#include "BlockCommand.h"

#include "../Containers/Container.h"
#include "../InterpreterFiles/Interpreter.h"

void BlockCommand::executeBlock(vector<string> &commands, int index) {
  int commandsSize = commands.size();
  while (index < commandsSize && commands.at(index).compare("}") != 0) { //while there are strings to read:
    if (container->GetMaps()->IsACommand(commands.at(index))) {
      //if this word is in the commands map, just run the command
      Command *c = container->GetMaps()->ReadCommand(commands.at(index));
      index += c->execute(commands, index);
    } else if (container->GetMaps()->InVars(commands.at(index))) {
      //should be a var name, so call the change var value command
      Command *c = container->GetMaps()->ReadCommand(NEW_VALUE_COMMAND);
      index += c->execute(commands, index);
    } else { //error or something we did not think about
      string message(commands.at(index) + " is not a command");
      throw message.c_str();
    }
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
