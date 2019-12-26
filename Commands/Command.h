//
// Created by yoav on 21/12/2019.
//

#ifndef EX3_COMMANDS_COMMAND_H_
#define EX3_COMMANDS_COMMAND_H_

#include <vector>
#include <string>
#include "../Containers/Container.h"

class Command{
 public:
  virtual int execute(vector<string>& params, int start, Container& container)=0;
};

#endif //EX3_COMMANDS_COMMAND_H_
