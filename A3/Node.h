#ifndef NODE_h
#define NODE_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{
public:
  Node* branches [26];
  bool isWord;
  std::string word;
  Node();
  bool getIsWord();
  void setIsWord(bool b);
  std::string getWord();
  void setWord(std::string s);
  Node& operator=(const Node& other);
};


#endif /* end of include guard: NODE_h */
