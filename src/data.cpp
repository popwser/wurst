#include "data.h"
#include <string>

using namespace std;

Data::Data() {
  type = 0;
  data_int = 0;
  data_float = 0;
  data_char = ' ';
  std::string data_string = " ";
}

void Data::setDataInt(const int &i) {
  data_int = i;
  type = 0;
}

void Data::setDataFloat(const float &f) {
  data_float = f;
  type = 1;
}

void Data::setDataChar(const char &c) {
  data_char = c;
  type = 2;
}

void Data::setDataString(const string &s) {
  data_string = s;
  type = 3;
}

string Data::getDataOverride() const {
  if(type == 0) {
    return to_string(data_int);
  }
  if(type == 1) {
    return to_string(data_float);
  }
  if(type == 2) {
    return to_string(data_char);
  }
  if(type == 3) {
    return data_string;
  }

  return "EMPTY";

}

Data::~Data() {
}
