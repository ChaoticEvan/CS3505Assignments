#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

Node::Node()
{
  branches[26];

  for(int i = 0; i < 26; i++)
  {
    branches[i] = NULL;
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
