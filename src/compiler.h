#pragma once
#include <string>
#include "data.h"
#include "command.h"
#include <vector>

class Compiler {

public:
  Compiler();
  static void compileLine(const std::string &line, const int &lineNum);
  static void init();
  static void cleanUp();

};
