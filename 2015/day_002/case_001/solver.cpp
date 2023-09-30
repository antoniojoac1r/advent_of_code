#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "aux.hpp"

int minimum(int a, int b, int c) {
  if (a <= b && a <= c) 
    return a;
  if (b <= a && b <= c)
    return b;
  return c;
}

int calc(std::string str) {
  std::vector<std::string> vet = aux::split(str, 'x');
  int A = aux::to<int>(vet[0]) * aux::to<int>(vet[1]);
  int B = aux::to<int>(vet[1]) * aux::to<int>(vet[2]);
  int C = aux::to<int>(vet[2]) * aux::to<int>(vet[0]);
  int surface = 2 * (A + B + C);
  int slack = minimum(A, B, C);
  return surface + slack;
}

int main() {
  int amount = 0;
  std::string in {};
  while (std::getline(std::cin,in)) {
    amount += calc(in);
  }
  std::cout << amount << '\n';
}
