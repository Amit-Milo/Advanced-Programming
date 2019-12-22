//
// Created by yoav on 22/12/2019.
//

#ifndef EX3__SIMULATORVAR_H_
#define EX3__SIMULATORVAR_H_

#include <string>
enum Wrapping { SIM_TO_PROG, PROG_TO_SIM, NONE };


using namespace std;
class SimulatorVar {
  double value;
  string progName;
  string simulatorName;
  Wrapping wrapping;
 public:
  SimulatorVar(const string &prog_name, const string &simulator_name, Wrapping wrapping);
  SimulatorVar(double value, const string &prog_name);
  double GetValue() const;
  void SetValue(double value);
  const string &GetProgName() const;
  void SetProgName(const string &prog_name);
  const string &GetSimulatorName() const;
  void SetSimulatorName(const string &simulator_name);
  Wrapping GetWrapping() const;
  void SetWrapping(Wrapping wrapping);
};

#endif //EX3__SIMULATORVAR_H_
