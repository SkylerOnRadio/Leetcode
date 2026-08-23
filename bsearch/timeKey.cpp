#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class TimeMap {
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> map;

public:
  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) {
    if (map.find(key) != map.end()) {
      map.find(key)->second.push_back({timestamp, value});

    } else {
      map.insert({key, {{timestamp, value}}});
    }
  }

  std::string get(std::string key, int timestamp) {
    std::string res{""};
    const auto &val = map.find(key);

    if (val != map.end()) {
      const auto &values = val->second;
      int low = 0;
      int high = values.size() - 1;
      int mid;

      while (high >= low) {
        mid = (high + low) / 2;

        if (values.at(mid).first > timestamp)
          high = mid - 1;
        else {
          res = values.at(mid).second;
          low = mid + 1;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  TimeMap *obj = new TimeMap();
  obj->set("love", "high", 10);
  obj->set("love", "low", 20);

  std::cout << obj->get("love", 5) << "\n";
  std::cout << obj->get("love", 10) << "\n";
  std::cout << obj->get("love", 15) << "\n";
  std::cout << obj->get("love", 20) << "\n";
  std::cout << obj->get("love", 25) << "\n";
  return 0;
}
