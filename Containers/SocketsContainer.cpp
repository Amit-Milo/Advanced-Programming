//
// Created by amit on 23/12/2019.
//

#include "SocketsContainer.h"
SocketsContainer::SocketsContainer() {
  // Create an instance of the sockets.
  this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
  this->client_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Equivalent to check (server_socket == -1) or (client_socket == -1)
  if (!(server_socket + 1) * (client_socket + 1))
    throw "Couldn't allocate socket.";
}
