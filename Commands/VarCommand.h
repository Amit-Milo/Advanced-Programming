//
// Created by yoav on 22/12/2019.
//

#ifndef EX3_COMMANDS_VARCOMMAND_H_
#define EX3_COMMANDS_VARCOMMAND_H_

#include <unordered_map>
#include "Command.h"
#include "../SimulatorVar.h"

#define DISTANCE_TO_PROG_VAR_NAME_ARROW_COMMAND 1
#define DISTANCE_TO_SIM_VAR_NAME_ARROW_COMMAND 4

class VarCommand : public Command {
 public:
  VarCommand(Container *container);
  void arrowCommand(vector<string> &params, int start, Wrapping wrapping);
};

#endif //EX3_COMMANDS_VARCOMMAND_H_
