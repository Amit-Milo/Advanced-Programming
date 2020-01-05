//
// Created by yoav on 04/01/2020.
//

#ifndef EX3_COMMANDS_SLEEPCOMMAND_H_
#define EX3_COMMANDS_SLEEPCOMMAND_H_

#include "Command.h"

//TODO amit comments

class SleepCommand : public Command {
 public:
  int execute(vector<string> &params, int start) override;
  SleepCommand(Container *container);
};

#endif //EX3_COMMANDS_SLEEPCOMMAND_H_
