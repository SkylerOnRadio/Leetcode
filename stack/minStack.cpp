#include <iostream>
#include <vector>
class MinStack {
  int topIndex{-1};
  std::vector<int> minIndex;
  std::vector<int> stackElements;

public:
  MinStack() {}

  void push(int value) {
    stackElements.push_back(value);
    ++topIndex;

    if (minIndex.empty()) {
      minIndex.push_back(topIndex);
      return;
    }

    if (stackElements.at(minIndex.back()) > stackElements.at(topIndex))
      minIndex.push_back(topIndex);
  }

  void pop() {
    if (topIndex == minIndex.back())
      minIndex.pop_back();
    stackElements.pop_back();
    --topIndex;
  }

  int top() { return stackElements.at(topIndex); }

  int getMin() { return stackElements.at(minIndex.back()); }
};

int main() {
  MinStack *minStack = new MinStack();
  minStack->push(-2);
  minStack->push(0);
  minStack->push(-3);
  std::cout << (minStack->getMin()) << "\n";
  minStack->pop();
  std::cout << (minStack->top()) << "\n";
  std::cout << (minStack->getMin()) << "\n";
  return 0;
}
