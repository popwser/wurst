#include <string>
#include <sstream>
#include <vector>
#include "data.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

void exitError(const string &error, const int &lineNum) {
  cout << error << " | line " << to_string(lineNum) << " | Fix dat!" << endl;
  exit(-1);
}

void exitErrorClean(const string &error, const int &lineNum) {
  cout << error << " | line " << to_string(lineNum) << " | Fix dat!" << endl;
}

bool isFilledWithSpaces(const string &s) {
  bool r = true;
  for(int i=0;i<s.length();i++) {
    if(s.at(i) != ' ')
      r = false;
  }

  return r;
}

bool isStringEmpty(const string &s) {
  return s == " " || s == "" || isFilledWithSpaces(s);
}

vector<string> splitString(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        if(!isStringEmpty(item)) {
          tokens.push_back(item);
        }
    }
    return tokens;
}

vector<string> splitStringRaw(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

// -i[data] -f[data] -c[data] -s[data] -![data] -?[data]
bool getData(string s, Data &final, int lineNum) {
  int pos[] = { -1, -1, -1, -1 };
  char type = 'n';
  Data data;
  for(int i=0;i<s.length();i++) {
    if(s.at(i) == '-') {
      pos[0] = i;
    }else if(s.at(i) == '!' || s.at(i) == '?'
      || s.at(i) == 'i' || s.at(i) == 'f'
        || s.at(i) == 'c' || s.at(i) == 's') {
          pos[1] = i;
          type = s.at(i);
    }else if(s.at(i) == '[') {
      pos[2] = i;
    }else if(s.at(i) == ']') {
      pos[3] = i;
    }
  }

  if(pos[0] == -1) {
    exitErrorClean("Expected '-' for Data", lineNum);
    return false;
  }
  if(pos[1] == -1) {
    exitErrorClean("Expected type after '-', for example '!' or 's'", lineNum);
    return false;
  }
  if(type == 'n') {
    exitErrorClean("Type " + s.substr(pos[1], pos[1] + 1) + " is not a valid type, \n expected one of the following: 'i' 'f' 'c' 's' '!' '?'", lineNum);
    return false;
  }
  if(pos[2] == -1) {
    exitErrorClean("Expected '[' to start Data param", lineNum);
    return false;
  }
  if(pos[3] == -1) {
    exitErrorClean("Expected ']' to close Data param", lineNum);
    return false;
  }

  int temp_len = abs(pos[3] - pos[2]);

  if(temp_len <= 1) {
    exitErrorClean("Cannot create Data from nothing", lineNum);
    return false;
  }

  string dataString = s.substr(pos[2]+1, temp_len-1);

  if(type == 'i') {
    data.setDataInt(stoi(dataString));
  }
  if(type == 'f') {
    data.setDataFloat(stof(dataString));
  }
  if(type == 'c') {
    if(dataString.length() > 1) {
      exitErrorClean("Cannot create char from multiple characters", lineNum);
      return false;
    }
    data.setDataChar(dataString.at(0));
  }
  if(type == 's') {
    data.setDataString(dataString);
  }
  if(type == '!') {
    data.setDataInt(0);
  }
  if(type == '?') {
    data.setDataInt(0);
  }

  final = data;

  return true;

}
