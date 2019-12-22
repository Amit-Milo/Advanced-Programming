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
#include "SimulatorVar.h"

using namespace std;
class Parser {
 private:
  unordered_map<string, Command *> commandsMap;
  unordered_map<string, SimulatorVar *> progVars;
  unordered_map<string, SimulatorVar *> simulatorVars;
  void setCommandsMap();
 public:
  Parser();
  void parse(vector<string> *commands);
};

#endif //EX3__PARSER_H_
