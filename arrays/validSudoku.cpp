#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  for (auto row : board) {
    std::unordered_map<char, int> numsPresent;
    for (auto element : row) {
      if (element == '.')
        continue;
      if (numsPresent.find(element) == numsPresent.end())
        numsPresent.insert({element, 1});
      else
        return false;
    }
  }

  for (int col = 0; col < 9; ++col) {
    std::unordered_map<char, int> numsPresent;
    for (int row = 0; row < 9; ++row) {
      char element = board.at(row).at(col);
      if (element == '.')
        continue;
      if (numsPresent.find(element) == numsPresent.end())
        numsPresent.insert({element, 1});
      else
        return false;
    }
  }
  int rowStart{0};
  int rowEnd{2};
  int colStart{0};
  int colEnd{2};
  while (rowEnd < 9) {
    while (colEnd < 9) {
      std::unordered_map<char, int> numsPresent;
      for (int row = rowStart; row <= rowEnd; ++row) {
        for (int col = colStart; col <= colEnd; ++col) {
          char element = board.at(row).at(col);
          if (element == '.')
            continue;
          if (numsPresent.find(element) == numsPresent.end()) {
            std::cout << element << " ";
            numsPresent.insert({element, 1});
          } else
            return false;
        }
      }
      colStart += 3;
      colEnd += 3;
    }
    std::cout << "\n";
    rowStart += 3;
    rowEnd += 3;
    colStart = 0;
    colEnd = 2;
  }
  return true;
}

int main() {
  std::vector<std::vector<char>> sudoku = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  std::vector<std::vector<char>> s2 = {
      {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  std::vector<std::vector<char>> s3 = {
      {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
      {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
      {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
      {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
      {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
      {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
      {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};

  bool valid = isValidSudoku(sudoku);

  std::boolalpha(std::cout);
  std::cout << valid << '\n';

  valid = isValidSudoku(s3);
  std::cout << '\n' << valid << '\n';
  return 0;
}
