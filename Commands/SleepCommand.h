//
// Created by yoav on 04/01/2020.
//

#ifndef EX3_COMMANDS_SLEEPCOMMAND_H_
#define EX3_COMMANDS_SLEEPCOMMAND_H_

#define DIStANCE_TO_SLEEP_VALUE 1
#include "Command.h"

class SleepCommand : public Command {
 public:
  /**
   * Execute the command. Block the execute of the current thread for a given time.
   * @param params a vector of parameters used by the command.
   * @param start index implying where to start reading from the vector.
   * @return how many jumps should be taken.
   */
  int execute(vector<string> &params, int start) override;

  /**
   * A constructor.
   * @param container contains important information about the program and related members.
   */
  SleepCommand(Container *container);
};

#endif //EX3_COMMANDS_SLEEPCOMMAND_H_
