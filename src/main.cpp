#include <iostream>
#include <string>
#include "compiler.h"

using namespace std;

int main(int argc, char* argv[]) {

/*  if(argc < 2) {
    cout << "No input files" << endl;
    exit(-1);
  } */

  //"print: "hello ", "world"
  Compiler::init();
  string testLine = "print: -i[10000]";

  Compiler::compileLine(testLine, 0);

  Compiler::cleanUp();

  return 0;
}
