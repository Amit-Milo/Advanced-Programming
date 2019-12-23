//
// Created by amit on 23/12/2019.
//

#ifndef EX3__SOCKETSCONTAINER_H_
#define EX3__SOCKETSCONTAINER_H_

#include <sys/socket.h>

#include "Container.h"
#include "OpenDataServerCommand.h"
#include "../ConnectControlClientCommand.h"

class SocketsContainer: public Container {
  // Those classes need to use the sockets.
  friend class OpenDataServerCommand;
  friend class ConnectControlClientCommand;

  // A socket used when the program functions as a server.
  int server_socket;

  // A socket used when the program functions as a client.
  int client_socket;

 public:
  SocketsContainer();
};

#endif //EX3__SOCKETSCONTAINER_H_
