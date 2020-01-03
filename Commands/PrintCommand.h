//
// Created by yoav on 04/01/2020.
//

#ifndef EX3_COMMANDS_PRINTCOMMAND_H_
#define EX3_COMMANDS_PRINTCOMMAND_H_

#include "Command.h"

class PrintCommand:public Command{
 public:
  int execute(vector<string> &params, int start) override;
  PrintCommand(Container *container);
};


#endif //EX3_COMMANDS_PRINTCOMMAND_H_
