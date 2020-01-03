//
// Created by yoav on 23/12/2019.
//

#ifndef EX3_COMMANDS_VARCOMMANDS_EQUALSIGNVARCOMMAND_H_
#define EX3_COMMANDS_VARCOMMANDS_EQUALSIGNVARCOMMAND_H_

#include "../VarCommand.h"

class EqualSignVarCommand:public VarCommand{
 public:
  int execute(vector<string> &params, int start) override;
  EqualSignVarCommand(Container *container);
};

#endif //EX3_COMMANDS_VARCOMMANDS_EQUALSIGNVARCOMMAND_H_
