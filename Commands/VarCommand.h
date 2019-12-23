//
// Created by yoav on 22/12/2019.
//

#ifndef EX3_COMMANDS_VARCOMMAND_H_
#define EX3_COMMANDS_VARCOMMAND_H_

#include <unordered_map>
#include "Command.h"
#include "../SimulatorVar.h"

class VarCommand : public Command {
  unordered_map<string, SimulatorVar *> *progVars;
  unordered_map<string, SimulatorVar *> *simulatorVars;
 public:
  VarCommand(unordered_map<string, SimulatorVar*> *prog_vars, unordered_map<string, SimulatorVar*> *simulator_vars);
};

#endif //EX3_COMMANDS_VARCOMMAND_H_
