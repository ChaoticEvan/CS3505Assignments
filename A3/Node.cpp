#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;


typedef std::vector<Node> branches;
bool isWord;

Node::Node() = default;

bool Node::getIsWord()
{
  return isWord;
}

void Node::setIsWord(bool b)
{
  isWord = b;
}

std::vector<Node>* Node::getBranches()
{
  return &branches;
}
