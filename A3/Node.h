#ifndef NODE_h
#define NODE_h

#include <iostream>
#include <vector>
using namespace std;

class Node
{
private:
  bool isWord;
  typedef std::vector<Node> branches;
public:
  Node();
  std::vector<Node>* getBranches();
  bool getIsWord();
  void setIsWord(bool b);
};

#endif /* end of include guard: NODE_h */
