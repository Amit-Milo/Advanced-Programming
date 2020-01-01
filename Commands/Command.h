//
// Created by yoav on 21/12/2019.
//

#ifndef EX3_COMMANDS_COMMAND_H_
#define EX3_COMMANDS_COMMAND_H_

#include <vector>
#include <string>
#include "../Containers/Container.h"

class Command{
 protected:
  Container* container;
 public:
  virtual int execute(vector<string>& params, int start)=0;
  Command(Container *container) : container(container) {}
};

#endif //EX3_COMMANDS_COMMAND_H_
