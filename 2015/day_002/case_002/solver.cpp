#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "aux.hpp"

int two_sides(const std::vector<int> &vet) {
  int plusV;
  std::vector<int> temp = vet;
  std::sort(temp.begin(),temp.end());
  plusV = temp[0] + temp[0] + temp[1] + temp[1];
  return plusV;
}

int calc(const std::string &str) {
  std::vector<int> vet = aux::to_vet<int>(aux::split(str, 'x'));
  int dimensions = vet[0] * vet[1] * vet[2];
  int plus = two_sides(vet);
  return dimensions + plus;
}

int main() {
  int amount = 0;
  std::string input {};
  while (std::getline(std::cin,input)) {
    amount += calc(input);
  }
  std::cout << amount << '\n';
}
