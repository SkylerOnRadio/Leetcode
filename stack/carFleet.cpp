#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>

int carFleet(int target, std::vector<int> &position, std::vector<int> &speed) {
  std::vector<std::vector<int>> cars;
  std::stack<float> fleet;

  for (int i = 0; i < position.size(); ++i) {
    cars.push_back({position.at(i), speed.at(i)});
  }
  std::sort(cars.begin(), cars.end(), std::greater<>());

  for (auto x : cars) {
    float speed = (static_cast<float>(target) - x.at(0)) / x.at(1);
    if (!fleet.empty()) {
      if (fleet.top() >= speed)
        continue;
    }
    fleet.push(speed);
  }

  return fleet.size();
}

int main() {
  std::vector<int> pos1 = {10, 8, 0, 5, 3};
  std::vector<int> speed1 = {2, 4, 1, 1, 3};
  std::vector<int> pos2 = {6, 8};
  std::vector<int> speed2 = {3, 2};
  std::vector<int> pos3 = {0, 2, 4};
  std::vector<int> speed3 = {4, 2, 1};

  std::cout << carFleet(12, pos1, speed1) << "\n";
  std::cout << carFleet(10, pos2, speed2) << "\n";
  std::cout << carFleet(100, pos3, speed3) << "\n";

  return 0;
}
