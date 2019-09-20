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
  void addAWordRec(std::string str, int idx, Node* curr);
  bool isAWord(std::string str);
  bool isAWordRec(std:: string str, int idx, Node* curr);
  vector<std::string> allWordsStartingWithPrefix(std::string str);
  vector<std::string> allWordsStartingWithPrefixRec(std::string str, int idx, Node* curr);
  void findWords(std::vector<std::string> *v, Node* curr);
};

#endif /* end of include guard: TRIE_h */
