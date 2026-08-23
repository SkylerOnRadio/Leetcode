#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::vector<std::string>>
groupAnagrams(std::vector<std::string> &str) {
  std::map<std::array<int, 26>, std::vector<std::string>> groups;
  std::array<int, 26> alpha = {0};
  for (std::string word : str) {
    for (char c : word) {
      int i = c - 'a';
      alpha[i]++;
    }
    if (groups.find(alpha) == groups.end()) {
      groups.insert({alpha, {word}});
      alpha = {0};
      continue;
    }
    auto x = groups.find(alpha);
    x->second.push_back(word);
    alpha = {0};
  }
  std::vector<std::vector<std::string>> wordGroups;
  for (auto &a : groups) {
    wordGroups.push_back(a.second);
  }
  return wordGroups;
}

int main() {
  std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
  std::vector<std::vector<std::string>> result = groupAnagrams(words);
  for (auto x : result) {
    for (auto y : x) {
      std::cout << y << "\t";
    }
    std::cout << "\n";
  }
  return 0;
}
