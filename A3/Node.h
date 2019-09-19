#ifndef NODE_h
#define NODE_h

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
  Node* branches [26];
  bool isWord;
  Node();
  bool getIsWord();
  void setIsWord(bool b);
  Node& operator=(const Node& other);
};


#endif /* end of include guard: NODE_h */
