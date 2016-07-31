#include "command_print.h"
#include <iostream>
#include <vector>

using namespace std;

CommandPrint::CommandPrint()
: Command("print", 1, 50) {

}

void CommandPrint::execute(vector<Data> data) {
  for(int i=0;i<data.size();i++) {
    cout << data[i].getDataOverride() << endl;
  }
}
