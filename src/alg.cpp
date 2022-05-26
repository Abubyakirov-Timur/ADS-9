// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> newTree;
  std::ifstream file(filename);
  std::string word = "";
  if (file.is_open()) {
    while (!file.eof()) {
      word = "";
      while (true) {
        char message = file.get();
        if ((message >= 97 && message <= 122) || (message >= 65 && message <= 90)) {
          word += tolower(message);
        } else {
          break;
        }
      }
      newTree.add(word);
    }
    return newTree;
  } else {
    throw std::string("Did`t open!");
  }
}
