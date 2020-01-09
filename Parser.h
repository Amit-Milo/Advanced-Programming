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
#include "Commands/VarCommands/ArrowCommands/RightArrowVarCommand.h"
#include "Commands/VarCommands/ArrowCommands/LeftArrowVarCommand.h"
#include "Commands/BlockCommand.h"
#include "SimulatorVar.h"

#include "Containers/Container.h"
#include "Containers/MapsContainer.h"

#define NEW_VALUE_COMMAND string("newValueCommand")
#define VAR_KEYWORD string("var")
#define DISTANCE_TO_VAR_DECLARATION_SIGN 2

using namespace std;
class Parser {
 public:
  Parser();
  /**
   * get the list of strings from lexer and run the program
   * @param commands the list of strings
   * @param container holds all the important vars
   */
  void parse(vector<string> *commands, Container *container);
};

#endif //EX3__PARSER_H_
