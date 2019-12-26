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
#include "Commands/BlockCommand.h"
#include "SimulatorVar.h"


#define NEW_VALUE_COMMAND string("newValueCommand")
#define VAR_KEYWORD string("var")

using namespace std;
class Parser {
  friend class BlockCommand;
 public:
  Parser();
  void parse(vector<string> *commands, Container &container);
};

#endif //EX3__PARSER_H_
