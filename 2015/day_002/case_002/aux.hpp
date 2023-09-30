#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace aux {
template<typename T>
T to(const std::string& c) {
  std::stringstream ss(c);
  T output;
  ss >> output;
  return output;
}
template<typename T>
std::vector<T> to_vet(const std::vector<std::string> &vet_str) {
  std::vector<T> vet;
  for (std::string element : vet_str)
    vet.push_back(to<T>(element));
  return vet;
}

inline std::vector<std::string> split(const std::string& in,const char &d) {
  std::vector<std::string> vet;
  std::stringstream ss(in);
  std::string token;
  while (std::getline(ss,token,d)) 
    vet.push_back(token);
  return vet;
}
}

