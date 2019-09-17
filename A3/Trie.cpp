#include <iostream>
#include <vector>
#include <string>
#include "Trie.h"
#include "Node.h"
using namespace std;

Node root();
Trie::Trie()
{
  Node root();

}

Trie::~Trie()
{

}

Trie::Trie(const Trie& trie)
{
}

Trie& Trie::operator=(const Trie& other)
{
  root = other.root;
}

void Trie::addAWord(std::string str)
{
  Node curr = root;

  std::vector<Node> test(26);
  curr.getBranches();

  for(int i = 0; i < str.length(); i++)
  {
    int idx = str.at(i) - 97;

    if(!curr.getBranches()[idx])
    {
      curr.getBranches()[idx]();
    }

    curr = curr.getBranches()[idx];

  }
}

bool Trie::isAWord(std::string str)
{
  return false;
}

vector<std::string> allWordsStartingWithPrefix(std::string str)
{
  return std::vector<std::string>();
}
