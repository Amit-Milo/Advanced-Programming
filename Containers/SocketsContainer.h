//
// Created by amit on 23/12/2019.
//

#ifndef EX3__SOCKETSCONTAINER_H_
#define EX3__SOCKETSCONTAINER_H_

#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

using namespace std;


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

  bool serverConnected = false;
  bool clientConnected = false;

 public:
  /**
   * A default constructor.
   */
  SocketsContainer();

  /**
   * Send given data to server (the simulator).
   * @param data the data to send the simulator.
   */
  void SendToServer(string data);
};

#endif //EX3__SOCKETSCONTAINER_H_
