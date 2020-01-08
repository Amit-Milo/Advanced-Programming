#include <iostream>
#include <string>
#include <fstream>

#include "Expressions/ExpressionsIncludes.h"
#include "InterpreterFiles/InterpreterIncludes.h"
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
      vector<string> *commands = l.lexer(argv[0]);

      Parser p;
      p.parse(commands, container);

      delete commands;
      delete container;
    } catch (char *e) {
      string error("exception: ");
      error.append(e);
      cout << error<< endl;
    }
  }
  return 0;
}