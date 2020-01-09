#include <iostream>
#include <string>

#include "Lexer.h"
#include "Containers/ContainerCreator.h"
#include "Parser.h"

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    cout << "file name not provided, can not run the program"<<endl;
  } else { //valid run, got the input file name
    try {
      ContainerCreator cc;
      Container *container = cc.createContainer();

      Lexer l;
      vector<string> *commands = l.lexer(argv[1]);

      Parser p;
      p.parse(commands, container);

      container->TerminateProgram();

      while (container->ThreadsOpen()) {}

      delete commands;
      delete container;
    } catch (char *e) {
      cout << strcat("exception: ", e) << endl;
    }
  }
  return 0;
}