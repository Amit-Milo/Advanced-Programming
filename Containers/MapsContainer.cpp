//
// Created by yoav on 26/12/2019.
//

#include "MapsContainer.h"

void MapsContainer::setCommandsMap() {
  commandsMap.insert({"openDataServer", new OpenDataServerCommand()});
  commandsMap.insert({"connectControlClient", new ConnectControlClientCommand()});
  commandsMap.insert({"=", new EqualSignVarCommand()});
  commandsMap.insert({"->", new RightArrowVarCommand()});
  commandsMap.insert({"<-", new LeftArrowVarCommand()});
  commandsMap.insert({NEW_VALUE_COMMAND, new ChangeValueCommand()});
  commandsMap.insert({"if", new IfCommand()});
  commandsMap.insert({"while", new WhileCommand()});
}

MapsContainer::MapsContainer() {
  setCommandsMap();
}

