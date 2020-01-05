#include <iostream>
#include <string>
#include <fstream>

#include "Expressions/ExpressionsIncludes.h"
#include "InterpreterFiles/InterpreterIncludes.h"
#include "Lexer.h"
#include "Containers/ContainerCreator.h"

int main() {

  Lexer l;
  vector<string> *commands = l.lexer("fly.txt");

  for (auto const &i : *commands) {
    std::cout << "*" << i << "*" << endl;
  }

  delete commands;



/*
  ContainerCreator cc;
  Container *container = cc.createContainer();


  // 6
  container->SetInterpreter(new Interpreter(container));
  Expression *e6 = nullptr;
  try {
    container->GetInterpreter()->setVariables("x=1.5;y=8.5");
    e6 = container->GetInterpreter()->interpret("-x-y");
    std::cout << "6: " << e6->calculate() << std::endl;//-10
    delete e6;
  } catch (const char *e) {
    if (e6 != nullptr) {
      delete e6;
    }
    std::cout << e << std::endl;
  }


  delete container;
  */

  return 0;
}


/*

  // 1
  Variable *x1 = new Variable("x1", 3);// x1=3
  Expression *e1 = nullptr;
  try {
    e1 = new Mul(new UMinus(new Value(5.0)), new Plus(new Value(3.5), &(++(*x1))));// -5*(3.5+(++x1))
    cout << "1: " << e1->calculate() << endl; //-37.5
    delete e1;
  } catch (const char *e) {
    if (e1 != nullptr) {
      delete e1;
    }
    std::cout << e << std::endl;
  }


  // 2
  Variable *x2 = new Variable("x2", 5.0);// x2=5.0
  Variable *x3 = new Variable("x3", 10.0);// x3=10.0
  Expression *e2 = nullptr;
  try {
    e2 = new Div(x3, new UMinus(new UPlus(new UMinus(x2))));// 10/-(+(-(5)))
    cout << "2: " << e2->calculate() << endl; //2
    delete e2;
  } catch (const char *e) {
    if (e2 != nullptr) {
      delete e2;
    }
    std::cout << e << std::endl;
  }

  // 3
  Variable *x4 = new Variable("x4", 2.0);// x4=2.0
  Variable *x5 = new Variable("x5", -4.5);// x5=-4.5
  Expression *e3 = nullptr;
  try {
    e3 = new Mul(&(++(*x4)), &((*x5)++));// (++x4)*(x5++)
    cout << "3: " << e3->calculate() << endl; //-10.5
    delete e3;
  } catch (const char *e) {
    if (e3 != nullptr) {
      delete e3;
    }
    std::cout << e << std::endl;
  }



  // 4
  container->SetInterpreter(new Interpreter(container));
  Expression *e4 = nullptr;
  try {
    e4 = container->GetInterpreter()->interpret("-(2*(3+4))");
    std::cout << "4: " << e4->calculate() << std::endl;//-14
    delete e4;
    delete container->GetInterpreter();
  } catch (const char *e) {
    if (e4 != nullptr) {
      delete e4;
    }
    if (container->GetInterpreter() != nullptr) {
      delete container->GetInterpreter();
    }
    std::cout << e << std::endl;
  }


  // 5
  container->SetInterpreter(new Interpreter(container));
  Expression *e5 = nullptr;
  try {
    container->GetInterpreter()->setVariables("x=2;y=4");
    container->GetInterpreter()->setVariables("x=3");
    e5 = container->GetInterpreter()->interpret("2*(-(x+y))");
    std::cout << "5: " << e5->calculate() << std::endl;//-14
    delete e5;
  } catch (const char *e) {
    if (e5 != nullptr) {
      delete e5;
    } //deleting i2 in the next example
    std::cout << e << std::endl;
  }

  // 6
  container->SetInterpreter(new Interpreter(container));
  Expression *e6 = nullptr;
  try {
    container->GetInterpreter()->setVariables("x=1.5;y=8.5");
    e6 = container->GetInterpreter()->interpret("-(-(-((x+0.5)*(y+(-3.5)))))");
    std::cout << "6: " << e6->calculate() << std::endl;//-10
    delete e6;
    delete container->GetInterpreter();
  } catch (const char *e) {
    if (e6 != nullptr) {
      delete e6;
    }
    std::cout << e << std::endl;
  }

  container->SetInterpreter(new Interpreter(container));
  Expression *e7 = nullptr;
  try {
    // 7
    container->GetInterpreter()->setVariables("x2=@;y=8.5");//error
    e7 = container->GetInterpreter()->interpret("-(-(-((x+0.5)*(y+(-3.5)))))");
    std::cout << "7: " << e7->calculate() << std::endl;
    delete e7;
    delete container->GetInterpreter();
  } catch (const char *e) {
    if (e7 != nullptr) {
      delete e7;
    }
    std::cout << e << std::endl;
  }

  // 8
  Expression *e8 = nullptr;
  try {
    e8 = new Div(new Value(1.0), new Value(0.0));// 1.0/0.0
    std::cout << "8: " << e8->calculate() << std::endl;// error
    delete e8;
  } catch (const char *e) {
    if (e8 != nullptr) {
      delete e8;
    }
    std::cout << e << std::endl;
  }

  // 9
  container->SetInterpreter(new Interpreter(container));
  Expression *e9 = nullptr;
  try {
    e9 = container->GetInterpreter()->interpret("1.0-(-(-16.0))");
    std::cout << "9: " << e9->calculate() << std::endl;// -15
    delete e9;
    delete container->GetInterpreter();
  } catch (const char *e) {
    if (e9 != nullptr) {
      delete e9;
    }
    std::cout << e << std::endl;
  }
  // 10
  container->SetInterpreter(new Interpreter(container));
  Expression *e10 = nullptr;
  try {
    container->GetInterpreter()->setVariables("x=1;y=2;z=3");
    e10 = container->GetInterpreter()->interpret("-(-(-((z+0.5)*(y+(-3.5)))))");
    std::cout << "10: " << e10->calculate() << std::endl;// 5.25
    delete e10;
    delete container->GetInterpreter();
  } catch (const char *e) {
    if (e10 != nullptr) {
      delete e10;
    }
    if (container->GetInterpreter() != nullptr) {
      delete container->GetInterpreter();
    }
    std::cout << e << std::endl;
  }

  container->SetInterpreter(new Interpreter(container));
  Expression *e11 = nullptr;
  try {
    // 11
    container->GetInterpreter()->setVariables("x2=14;y=8.5");
    e11 = container->GetInterpreter()->interpret("-(-(-((x+0.5)**(y+(-3.5)))))"); //error
    std::cout << "11: " << e11->calculate() << std::endl;
    delete e11;
    delete container->GetInterpreter();
  } catch (const char *e) {
    if (e11 != nullptr) {
      delete e11;
    }
    std::cout << e << std::endl;
  }
  return 0;



4: -14
5: -14
6: -10
illegal variable assignment!
8: division by zero
9: -15
10: 5.25
illegal math expression
*/