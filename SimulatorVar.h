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
  /**
   * constructor for var associated with simulator var
   * @param prog_name the program var name
   * @param simulator_name the simulator var name
   * @param wrapping the wrappinf side
   * set the value of to the simulator var's value
   */
  SimulatorVar(const string &prog_name, const string &simulator_name, Wrapping wrapping);
  /**
   * constructor for var not associated with simulator var.
   * the simulatorName field is empty, the wrapping is NONE.
   * @param value the var's value
   * @param prog_name the var's name.
   */
  SimulatorVar(double value, const string &prog_name);

  //getters and setters:
  double GetValue() const;
  /**
   * special setter, sets the value according to the wrapping.
   * @param value the new value.
   */
  void SetValue(double value);
  const string &GetProgName() const;
  void SetProgName(const string &prog_name);
  const string &GetSimulatorName() const;
  void SetSimulatorName(const string &simulator_name);
  Wrapping GetWrapping() const;
  void SetWrapping(Wrapping wrapping);
};

#endif //EX3__SIMULATORVAR_H_
