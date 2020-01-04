
#ifndef PROJECT_EXPRESSION_H
#define PROJECT_EXPRESSION_H

using namespace std;
/**
 * Expression Interface
 */
class Expression {
 public:
  /**
   * calculate the expression value
   * @return the expression value
   */
  virtual double calculate() = 0;
  virtual ~Expression() {}
};

#endif //PROJECT_EXPRESSION_H
