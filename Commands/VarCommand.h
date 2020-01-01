//
// Created by yoav on 22/12/2019.
//

#ifndef EX3_COMMANDS_VARCOMMAND_H_
#define EX3_COMMANDS_VARCOMMAND_H_

#include <unordered_map>
#include "Command.h"
#include "../SimulatorVar.h"

class VarCommand : public Command {
 public:
  VarCommand(Container *container);
};

#endif //EX3_COMMANDS_VARCOMMAND_H_
