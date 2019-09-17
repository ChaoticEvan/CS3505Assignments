#ifndef TRIE_h
#define TRIE_h

#include <iostream>
#include <vector>
#include <string>
#include "Node.h"
using namespace std;

class Trie
{
private:
  Node root;
public:
  Trie();
  ~Trie();
  Trie(const Trie& trie);
  Trie& operator=(const Trie& other);
  void addAWord(std::string str);
  bool isAWord(std::string str);
  vector<std::string> allWordsStartingWithPrefix(std::string str);
};

#endif /* end of include guard: TRIE_h */
