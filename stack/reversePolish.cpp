#include <iostream>
#include <stack>
#include <string>
#include <vector>
int evalRPN(std::vector<std::string> &tokens) {
  std::stack<int> resultantStack;
  for (std::string token : tokens) {
    if (token == "+" || token == "-" || token == "/" || token == "*") {
      int num2 = resultantStack.top();
      resultantStack.pop();
      int num1 = resultantStack.top();
      resultantStack.pop();
      int res;
      if (token == "+")
        res = num1 + num2;
      else if (token == "-")
        res = num1 - num2;
      else if (token == "*")
        res = num1 * num2;
      else
        res = num1 / num2;
      resultantStack.push(res);
    } else {
      int num = std::stoi(token);
      resultantStack.push(num);
    }
  }
  return resultantStack.top();
}

int main() {
  std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
  std::vector<std::string> tokens1 = {"4", "13", "5", "/", "+"};
  std::vector<std::string> tokens2 = {"10", "6", "9",  "3", "+", "-11", "*",
                                      "/",  "*", "17", "+", "5", "+"};

  std::cout << "The result is " << evalRPN(tokens) << "\n";
  std::cout << "The result is " << evalRPN(tokens1) << "\n";
  std::cout << "The result is " << evalRPN(tokens2) << "\n";

  return 0;
}
