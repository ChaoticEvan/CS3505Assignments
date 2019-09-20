#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
    curr->setIsWord(true);
    curr->setWord(str);
    return;
  }

  int charIdx = str.at(idx) - 97;

  if(!curr->branches[charIdx])
  {
    Node *node = new Node();
    curr->branches[charIdx] = node;
  }

  idx++;
  addAWordRec(str, idx, curr->branches[charIdx]);
}

bool Trie::isAWord(std::string str)
{
  return isAWordRec(str, 0, &root);
}

bool Trie::isAWordRec(std::string str, int idx, Node* curr)
{
  if(idx == str.length())
  {
    return curr->getIsWord();
  }

  int charIdx = str.at(idx) - 97;

  if(!curr->branches[charIdx])
  {
    return false;
  }

  idx++;
  return isAWordRec(str, idx, curr->branches[charIdx]);
}

vector<std::string> Trie::allWordsStartingWithPrefix(std::string str)
{
  if(str.length() == 0)
  {
    std::vector<std::string> v;
    return v;
  }
  return allWordsStartingWithPrefixRec(str, 0, &root);
}

vector<std::string> Trie::allWordsStartingWithPrefixRec(std::string str, int idx, Node* curr)
{
  vector<std::string> result;
  if(idx == str.length())
  {
    findWords(&result, curr);
    if(isAWord(str))
    {
      result.push_back(str);
    }
    return result;
  }

  int charIdx = str.at(idx) - 97;

  if(!curr->branches[charIdx])
  {
    return result;
  }

  idx++;
  return allWordsStartingWithPrefixRec(str, idx, curr->branches[charIdx]);
}

void Trie::findWords(std::vector<std::string> *v, Node* curr)
{
  stack<Node*> s;
  s.push(curr);

  while(!s.empty())
  {
    Node *node = s.top();
    s.pop();

    for(int i = 0; i < 26; i++)
    {
      if(!node->branches[i])
      {
        continue;
      }

      s.push(node->branches[i]);

      if(node->branches[i]->getIsWord())
      {
        v->push_back(node->branches[i]->getWord());
      }
    }
  }
}
