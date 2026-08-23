#include <array>
#include <ios>
#include <iostream>
#include <map>
#include <string>

bool isAnagram(std::string s, std::string t) {
  std::array<int, 26> alphabet = {0};
  std::map<std::array<int, 26>, std::string> map;

  for (char c : s) {
    int index = c - 'a';
    alphabet[index]++;
  }
  map.insert({alphabet, s});
  alphabet = {0};

  for (char c : t) {
    int index = c - 'a';
    alphabet[index]++;
  }
  if (map.find(alphabet) == map.end())
    return false;
  return true;
}

int main() {
  std::string s = "ran";
  std::string t = "tar";
  bool isAnag = isAnagram(s, t);
  std::boolalpha(std::cout);
  std::cout << isAnag << "\n";
  return 0;
}
