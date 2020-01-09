//
// Created by yoav on 05/01/2020.
//

#ifndef EX3_COMMANDS_BLOCKCOMMANDS_FUNCTIONCOMMAND_H_
#define EX3_COMMANDS_BLOCKCOMMANDS_FUNCTIONCOMMAND_H_

#include "../BlockCommand.h"

#define DISTANCE_TO_INPUT_VAR_VALUE 1
#define DISTANCE_TO_NAME_OF_DECLARED_VAR 2
#define RETURN_VALUE_FROM_FUNCTION_CALL 2
#define DISTANCE_TO_BLOCK_START_AT_DECLARATION 4

class FunctionCommand : public BlockCommand {
  int funcStartInLexer;
 public:
  FunctionCommand(Container *container, int func_start_in_lexer);
  int execute(vector<string> &params, int start) override;
};

#endif //EX3_COMMANDS_BLOCKCOMMANDS_FUNCTIONCOMMAND_H_
