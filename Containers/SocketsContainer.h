//
// Created by amit on 23/12/2019.
//

#ifndef EX3__SOCKETSCONTAINER_H_
#define EX3__SOCKETSCONTAINER_H_

#include <netinet/in.h>
#include <sys/socket.h>

//TODO amit comments

class SocketsContainer {
  // Those classes need to use the sockets.
  friend class ConnectControlClientCommand;
  friend class OpenDataServerCommand;

  // A socket used when the program functions as a server.
  int server_socket;

  // Address object for the server.
  sockaddr_in server_address;

  // A socket used when the program functions as a client.
  int client_socket;

  // Address object for the client.
  sockaddr_in client_address;

 public:
  SocketsContainer();
};

#endif //EX3__SOCKETSCONTAINER_H_
