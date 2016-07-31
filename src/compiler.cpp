#include <iostream>
#include "compiler.h"
#include <string>
#include <vector>
#include "toolbox.h"
#include "commands/command_print.h"

using namespace std;

vector<Command*> commands;

Compiler::Compiler() {
}

void Compiler::init() {
  Command *command_print = new CommandPrint();
  commands.push_back(command_print);
}

void Compiler::cleanUp() {
  for(int i=0;i>commands.size();i++) {
    delete commands[i];
  }
}

bool commandExists(const string &commandName) {
  for(int i=0;i<commands.size();i++) {
    if(commands[i]->getName() == commandName) {
      return true;
    }
  }
  return false;
}

int getCommandIndex(const string &commandName) {
  for(int i=0;i<commands.size();i++) {
    if(commands[i]->getName() == commandName) {
      return i;
    }
  }
  return 0;
}

bool commandParamsMatched(const int &params, const int &command) {
  return commands[command]->verifyParams(params);
}

bool commandIsVoid(const int &command) {
  return commands[command]->isVoid();
}

string cleanStringAll(const string &s, const char &r) {
  string final = "";
  for(int i=0;i<s.length();i++) {
    if(!(s.at(i) == r))
      final += s.at(i);
  }
  return final;
}

string cleanStringBefore(const string &s, const char &r) {
  string final = "";
  int reachedLine = 0;

  for(int i=0;i<s.length();i++) {
    if(reachedLine == 1)
      final += s.at(i);
    if(i < s.length() - 1 && reachedLine == 0 && s.at(i+1) != r)
      reachedLine = 1;
  }

  return final;
}

void Compiler::compileLine(const string &linePass, const int &lineNum) {

  string line = linePass + " ";

  vector<string> tokens_pre = splitString(line, ':');
  if(tokens_pre.size() < 1)
    return;

  tokens_pre[0] = cleanStringAll(tokens_pre[0], ' ');

  if(!commandExists(tokens_pre[0]))
    exitError("Command: \"" + tokens_pre[0] + "\" does not exist", lineNum);

    int commandIndex = getCommandIndex(tokens_pre[0]);

  if(!commandIsVoid(commandIndex))
    if(tokens_pre.size() < 2)
      exitError("Expected parameters for command: " + tokens_pre[0], lineNum);

  tokens_pre[1] = cleanStringBefore(tokens_pre[1], ' ');

  vector<string> params = splitStringRaw(tokens_pre[1], ',');

  for(int i=0;i<params.size();i++) {
    if(isStringEmpty(params[i])) {
      exitError("Expected param after ','", lineNum);
    }
  }

  vector<Data> paramData;

  for(int i=0;i<params.size();i++) {
    Data data;
    if(!getData(params[i], data, lineNum)) {
      exit(-1);
    }
    paramData.push_back(data);
  }

  if(!commandParamsMatched(paramData.size(), commandIndex)) {
    exitError("Parameter count not in range for command: " + tokens_pre[0], lineNum);
  }

  commands[commandIndex]->execute(paramData);

}
