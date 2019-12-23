//
// Created by yoav on 21/12/2019.
//

#ifndef EX3__PARSER_H_
#define EX3__PARSER_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "Commands/Command.h"
#include "Commands/OpenDataServerCommand.h"
#include "Commands/ConnectControlClientCommand.h"

#include "Commands/VarCommand.h"
#include "Commands/VarCommands/ChangeValueCommand.h"
#include "Commands/VarCommands/EqualSignVarCommand.h"
#include "Commands/VarCommands/RightArrowVarCommand.h"
#include "Commands/VarCommands/LeftArrowVarCommand.h"
#include "SimulatorVar.h"

using namespace std;
class Parser {
 private:
  unordered_map<string, pair<Command *, int>> commandsMap; //pair is (related command,places to jump in commands vector)
  ///////////////////////////////////move to another class (the friend one)
  unordered_map<string, SimulatorVar *> progVars;
  unordered_map<string, SimulatorVar *> simulatorVars;
  void setCommandsMap();
 public:
  Parser();
  void parse(vector<string> *commands);
};

#endif //EX3__PARSER_H_
