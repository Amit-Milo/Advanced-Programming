//
// Created by yoav on 23/12/2019.
//

#ifndef EX3_COMMANDS_CHANGEVALUECOMMAND_H_
#define EX3_COMMANDS_CHANGEVALUECOMMAND_H_

#include "../VarCommand.h"
#define DISTANCE_TO_NEW_VAL 2

class ChangeValueCommand:public VarCommand{
 public:
  int execute(vector<string> &params, int start) override;
  ChangeValueCommand(Container *container);
};

#endif //EX3_COMMANDS_CHANGEVALUECOMMAND_H_
