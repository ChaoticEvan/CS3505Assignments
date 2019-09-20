#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

Node::Node()
{
  isWord = false;

  for(int i = 0; i < 26; i++)
  {
    branches[i] = nullptr;
  }
}

bool Node::getIsWord()
{
  return isWord;
}

void Node::setIsWord(bool b)
{
  isWord = b;
}

Node& Node::operator=(const Node& other)
{
  for(int i = 0; i < 26; i++)
  {
    branches[i] = other.branches[i];
  }
  isWord = other.isWord;
  return *this;
}
