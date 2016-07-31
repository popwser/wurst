#include "command.h"
#include "data.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Command::Command(string name, int minP, int maxP) {
  this->name = name;
  paramMin = minP;
  paramMax = maxP;
  paramDiff0 = (minP == maxP); //doesn't take params
}
Command::~Command() {
}
/*Override the following if needed:
  destroyPointers - place to destroy pointers which gets called in destructor last
*/
