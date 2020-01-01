//
// Created by yoav on 26/12/2019.
//

#include "MapsContainer.h"

#include "../Commands/OpenDataServerCommand.h"
#include "../Commands/ConnectControlClientCommand.h"
#include "../Commands/VarCommand.h"
#include "../Commands/VarCommands/ChangeValueCommand.h"
#include "../Commands/VarCommands/EqualSignVarCommand.h"
#include "../Commands/VarCommands/RightArrowVarCommand.h"
#include "../Commands/VarCommands/LeftArrowVarCommand.h"
#include "../Commands/BlockCommand.h"
#include "../Commands/BlockCommands/WhileCommand.h"
#include "../Commands/BlockCommands/IfCommand.h"

void MapsContainer::setCommandsMap() {
  commands.insert({"openDataServer", new OpenDataServerCommand(container)});
  commands.insert({"connectControlClient", new ConnectControlClientCommand(container)});
  commands.insert({"=", new EqualSignVarCommand(container)});
  commands.insert({"->", new RightArrowVarCommand(container)});
  commands.insert({"<-", new LeftArrowVarCommand(container)});
  commands.insert({NEW_VALUE_COMMAND, new ChangeValueCommand(container)});
  commands.insert({"if", new IfCommand(container)});
  commands.insert({"while", new WhileCommand(container)});
}

MapsContainer::MapsContainer() {
  setCommandsMap();
}

