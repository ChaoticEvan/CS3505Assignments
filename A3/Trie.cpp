#include <iostream>
#include <vector>
#include <string>
#include "Trie.h"
#include "Node.h"
using namespace std;

Node root();
Trie::Trie() = default;

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
    addAWordRec(str, 0, &root);
}

void Trie::addAWordRec(std::string str, int idx, Node* curr)
{
  if(idx == str.length())
  {
    return;
  }

  int charIdx = str.at(idx) - 97;

  if(!curr->branches[idx])
  {
    Node* node;
    curr->branches[idx] = node;
  }

  idx++;
  addAWordRec(str, idx, curr->branches[idx]);
}

bool Trie::isAWord(std::string str)
{
  return false;
}

vector<std::string> allWordsStartingWithPrefix(std::string str)
{
  return std::vector<std::string>();
}
