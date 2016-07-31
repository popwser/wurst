#pragma once
#include <string>

class Data {
public:
  Data();
  ~Data();
private:
  int type;
  int data_int;
  float data_float;
  char data_char;
  std::string data_string;

public:
  //type 0 = int, type 1 = float, type 2 = char, type 3 = str
  inline int getType() { return type; };
  inline int getDataInt() { return data_int; };
  inline float getDataFloat() { return data_float; };
  inline char getDataChar() { return data_char; };
  inline std::string getDataString() { return data_string; };
  void setDataInt(const int &i);
  void setDataFloat(const float &f);
  void setDataChar(const char &c);
  void setDataString(const std::string &s);
  std::string getDataOverride() const;

};
