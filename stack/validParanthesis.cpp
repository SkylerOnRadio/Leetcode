#include <ios>
#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string s) {
  std::stack<char> st;
  for (char c : s) {
    if (c == ')' || c == '}' || c == ']') {
      char needed;
      if (c == ')')
        needed = '(';
      else if (c == '}')
        needed = '{';
      else
        needed = '[';

      if (st.empty())
        return false;
      if (st.top() != needed)
        return false;
      st.pop();

    } else
      st.push(c);
  }
  if (!st.empty())
    return false;

  return true;
}

int main() {
  std::string s1 = "()";
  std::string s2 = "()[]{}";
  std::string s3 = "{]";
  std::string s4 = "{";
  std::string s5 = "({[)";

  std::boolalpha(std::cout);
  std::cout << isValid(s1) << "\n";
  std::cout << isValid(s2) << "\n";
  std::cout << isValid(s3) << "\n";
  std::cout << isValid(s4) << "\n";
  std::cout << isValid(s5) << "\n";
  return 0;
}
