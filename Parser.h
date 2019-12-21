//
// Created by yoav on 21/12/2019.
//

#ifndef EX3__PARSER_H_
#define EX3__PARSER_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "Commands/Command.h"

using namespace std;
class Parser {
 private:
  unordered_map<string, Command> commandsMap;
  void setCommandsMap();
 public:
  void parse(vector<string> *commands);
  Parser();
};

#endif //EX3__PARSER_H_
