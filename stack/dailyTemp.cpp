#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

std::vector<int> dailyTemp(std::vector<int> &temps) {
  std::vector<int> res(temps.size(), 0);

  std::stack<std::vector<int>> tempStore;

  for (int i = 0; i < temps.size(); ++i) {
    while (!tempStore.empty() && temps.at(i) > tempStore.top().at(0)) {
      int indice = tempStore.top().at(1);
      res.at(indice) = i - indice;
      tempStore.pop();
    }
    tempStore.push({temps.at(i), i});
  }

  while (!tempStore.empty()) {
    int indice = tempStore.top().at(1);
    res.at(indice) = 0;
    tempStore.pop();
  }

  return res;
}

std::vector<int> bruteForce(std::vector<int> &temps) {
  std::vector<int> res;
  for (int i = 0; i < temps.size(); ++i) {
    for (int j = i + 1; j < temps.size(); ++j) {
      if (temps.at(j) > temps.at(i)) {
        res.push_back(j - i);
        break;
      }
    }
    if (res.size() != i + 1)
      res.push_back(0);
  }
  return res;
}

int main() {
  std::vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> temps1 = {30, 40, 50, 60};
  std::vector<int> temps2 = {30, 60, 90};

  std::vector<int> res = dailyTemp(temps2);

  for (int x : res)
    std::cout << x << "\n";
  return 0;
}
