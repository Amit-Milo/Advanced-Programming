//
// Created by yoav on 04/01/2020.
//

#ifndef EX3_COMMANDS_VARCOMMANDS_ARROWVARCOMMAND_H_
#define EX3_COMMANDS_VARCOMMANDS_ARROWVARCOMMAND_H_

#include "../VarCommand.h"

#define DISTANCE_TO_PROG_VAR_NAME_ARROW_COMMAND 1
#define DISTANCE_TO_SIM_VAR_NAME_ARROW_COMMAND 4

class ArrowVarCommand: public VarCommand{
 public:
  ArrowVarCommand(Container *container);
  /**
   * save code by calling this func from both RightArrow and LeftArrow. this function adds the new var to the vars map.
   * @param params the vector of commands.
   * @param start the index of the word "var", first word in the command line.
   * @param wrapping the wrapping direction.
   */
  void arrowCommand(vector<string> &params, int start, Wrapping wrapping);
};

#endif //EX3_COMMANDS_VARCOMMANDS_ARROWVARCOMMAND_H_
