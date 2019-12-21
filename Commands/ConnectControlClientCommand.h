//
// Created by yoav on 21/12/2019.
//

#ifndef EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_
#define EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_

#include "Command.h"
class ConnectControlClientCommand: public Command{
 public:
  int execute() override;
};

#endif //EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_
