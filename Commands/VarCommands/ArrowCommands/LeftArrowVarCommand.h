//
// Created by yoav on 23/12/2019.
//

#ifndef EX3_COMMANDS_VARCOMMANDS_LEFTARROWVARCOMMAND_H_
#define EX3_COMMANDS_VARCOMMANDS_LEFTARROWVARCOMMAND_H_

#include "../ArrowVarCommand.h"

class LeftArrowVarCommand:public ArrowVarCommand{
 public:
  int execute(vector<string> &params, int start) override;
  LeftArrowVarCommand(Container *container);
};

#endif //EX3_COMMANDS_VARCOMMANDS_LEFTARROWVARCOMMAND_H_
