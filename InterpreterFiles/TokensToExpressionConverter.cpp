//
// Created by yoav on 17/11/2019.
//



#include "TokensToExpressionConverter.h"
#include "../Expressions/Value.h"
#include "../Expressions/BinOperators/Mul.h"
#include "../Expressions/BinOperators/Div.h"
#include "../Expressions/BinOperators/Plus.h"
#include "../Expressions/BinOperators/Minus.h"
#include "../Expressions/Variable.h"

/**
 * works only for /,*,-,+
 * @param s1 first operator
 * @param s2 second operator
 * @return 1 if s1>s2, -1 if s2>s1, 0 if s1=s2
 */
int TokensToExpressionConverter::compareOperators(string s1, string s2) {
  CalculationTokensCreatorChecker ctcc;
  if (ctcc.isBraces(s1)) {
    if (ctcc.isBraces(s2)) {
      return 0;
    } else {
      return 1;
    }
  } else { //s1 is operator
    if (ctcc.isBraces(s2)) {
      return -1;
    } else { //both are operators
      if (s1.compare("*") == 0 || s1.compare("/") == 0) {
        if (s2.compare("*") == 0 || s2.compare("/") == 0) {
          return 0;
        }
        //s2= -/+
        return 1;
      } else {//s1= -/+
        if (s2.compare("*") == 0 || s2.compare("/") == 0) {
          return -1;
        }
        //s2= -/+
        return 0;
      }
    }
  }
}

Expression *TokensToExpressionConverter::tokensToExpression(list<pair<string, int>> *tokens,
                                                            map<string, double> *variables) {
  stack<pair<string, int>> *s = tokensToStack(tokens);
  //printStack(s);
  Expression *exp = stackToExpression(s, variables);
  delete s;
  return exp;
}

/**
 * just implementation of shunting-yard algorithm from wikipedia
 * @param tokens
 * @return
 */
stack<pair<string, int>> *TokensToExpressionConverter::tokensToStack(list<pair<string, int>> *tokens) {
  stack<pair<string, int>> operatorsStack;
  deque<pair<string, int>> outputQueue;
  for (const auto &myPair : *tokens) {
    if (myPair.second == NUMBER || myPair.second == VARIABLE) {
      outputQueue.push_back(myPair);
    } else if (myPair.second == OPERATOR) {
      while (!operatorsStack.empty() && (compareOperators(myPair.first, operatorsStack.top().first) <= 0
          || operatorsStack.top().first.compare(")") == 0) && operatorsStack.top().first.compare("(") != 0) {
        pair<string, int> stackTop = operatorsStack.top();
        operatorsStack.pop();
        outputQueue.push_back(stackTop);
      }
      operatorsStack.push(myPair);
    } else if (myPair.first.compare("(") == 0) {
      operatorsStack.push(myPair);
    } else if (myPair.first.compare(")") == 0) {
      while (operatorsStack.top().first.compare("(") != 0) {
        pair<string, int> stackTop = operatorsStack.top();
        operatorsStack.pop();
        outputQueue.push_back(stackTop);
      }
      operatorsStack.pop();
    }
  }
  while (!operatorsStack.empty()) {
    pair<string, int> stackTop = operatorsStack.top();
    operatorsStack.pop();
    outputQueue.push_back(stackTop);
  }


  //clear deque in reverse to returned stack
  stack<pair<string, int>> *calcStack = new stack<pair<string, int>>;
  while (!outputQueue.empty()) {
    pair<string, int> temp = outputQueue.front();
    calcStack->push(temp);
    outputQueue.pop_front();
  }

  return calcStack;
}


Expression *TokensToExpressionConverter::stackToExpression(stack<pair<string, int>> *calcStack,
                                                           map<string, double> *variables) {
  if (calcStack->size() == 1) {
    return new Value(stod(calcStack->top().first));
  }
  if (calcStack->top().second == OPERATOR) {
    //things will work because once the function gets to a dead end it only leaves the other side of the expression
    string o = calcStack->top().first;
    calcStack->pop();
    //expression are switched on purpose
    Expression *right = stackToExpression(calcStack, variables);
    Expression *left = stackToExpression(calcStack, variables);
    if (o.compare("*") == 0) {
      return new Mul(left, right);
    } else if (o.compare("/") == 0) {
      return new Div(left, right);
    } else if (o.compare("+") == 0) {
      return new Plus(left, right);
    } else if (o.compare("-") == 0) {
      return new Minus(left, right);
    } else {
      throw "error in operator";
    }
  } else { //it is a number or a variable
    pair<string, int> top = calcStack->top();
    calcStack->pop();
    if (top.second == NUMBER) {
      return new Value(stod(top.first));
    } else if (top.second == VARIABLE) {
      return new Variable(top.first, variables->at(top.first));
    } else {
      throw "error in vars/numbers";
    }
  }
}

void TokensToExpressionConverter::printStack(stack<pair<string, int>> *s) {
  while (!s->empty()) {
    string ss = s->top().first;
    std::cout << ss << "," << std::flush;
    s->pop();
  }

}
/*
while there are tokens to be read do:
    read a token.
    if the token is a number, then:
        push it to the output queue.
    if the token is an operator, then:
        while ((there is a function at the top of the operator stack)
               or (there is an operator at the top of the operator stack with greater precedence)
               or (the operator at the top of the operator stack has equal precedence and is left associative))
              and (the operator at the top of the operator stack is not a left parenthesis):
            pop operators from the operator stack onto the output queue.
        push it onto the operator stack.
    if the token is a left paren (i.e. "("), then:
        push it onto the operator stack.
    if the token is a right paren (i.e. ")"), then:
        while the operator at the top of the operator stack is not a left paren:
            pop the operator from the operator stack onto the output queue.
        // if the stack runs out without finding a left paren, then there are mismatched parentheses.
if there is a left paren at the top of the operator stack, then:
pop the operator from the operator stack and discard it
    after while loop, if operator stack not null, pop everything to output queue
if there are no more tokens to read then:
while there are still operator tokens on the stack:
// if the operator token on the top of the stack is a paren, then there are mismatched parentheses.
pop the operator from the operator stack onto the output queue.
exit.
*/