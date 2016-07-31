#pragma once
#include "../command.h"
#include "../data.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CommandPrint: public Command {
public:
  CommandPrint();

  void execute(vector<Data> data);

};
