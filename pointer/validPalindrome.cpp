#include <ios>
#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
  std::string fixedWord{""};

  for (char c : s) {
    if ((c < 'a' || c > 'z') && (c < 48 || c > 57)) {
      if (c >= 'A' && c <= 'Z')
        fixedWord += c - ('A' - 'a');
    } else {
      fixedWord += c;
    }
  }

  int i = 0;
  int j = fixedWord.size() - 1;

  while (j >= i) {
    if (fixedWord[i] != fixedWord[j])
      return false;
    j--;
    i++;
  }

  return true;
}

int main() {
  std::string phrase = "A man, a plan, a canal: Panama";
  std::string phrase1 = "race a car";
  std::string phrase2 = "0P";
  std::boolalpha(std::cout);

  std::cout << isPalindrome(phrase) << "\n";
  std::cout << isPalindrome(phrase1) << "\n";
  std::cout << isPalindrome(phrase2) << "\n";
  return 0;
}
