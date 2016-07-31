#pragma once

#include <string>
#include "data.h"
#include <vector>
#include <iostream>

class Command {

public:
  Command(std::string name, int minP, int maxP);
  ~Command();
  inline bool verifyParams(int params) { return params <= paramMax && params >= paramMin; };
  inline std::string getName() { return name; };
  inline bool isVoid() { return paramDiff0; };
  virtual void execute(std::vector<Data> data) {
    std::cout << "Base execution, make sure to override" << std::endl;
  };
protected:
  /*Override the following if needed:
    execute - executes whatever needs to be executed and gets passed params
  */
  std::string name;
  int paramMin;
  int paramMax;
  bool paramDiff0;

};
