#include <algorithm>
#include <iostream>
#include <string>

int case_one(std::string in) {
  int up = std::count_if(
    in.begin(),
    in.end(),
    [](char e) {
      return e == '(';
    }
  );
  int down = std::count_if(
    in.begin(),
    in.end(),
    [](char e) {
      return e == ')';
    }
  );
  return up - down;
}

int case_two(std::string &in) {
  int indexOfBreak = 0;
  for (int index = 0; index <= (int) in.size(); index++) {
    if (indexOfBreak < 0)
      return index;
    if (in[index] == '(')
      indexOfBreak++;
    else
      indexOfBreak--;
  }
  return -1;
}

int main() {
  std::string lineReader {""};
  std::getline(std::cin, lineReader);
  std::cout << "case one: " << case_one(lineReader) << '\n';
  std::cout << "case two: " << case_two(lineReader) << '\n';
}
