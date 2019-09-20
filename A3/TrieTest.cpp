#include <fstream>
#include "Trie.cpp"
#include "Node.cpp"

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    std::cerr << "Did not provide the correct amount of arguments" << '\n';
    return -99;
  }
  Trie *test = new Trie();
  string wordsPath = argv[1];
  string testingPath = argv[2];

  fstream words;
  words.open(wordsPath);
  if(words.fail())
  {
    std::cerr << "Input file could not be opened" << '\n';
    return -99;
  }

  fstream testingWords;
  testingWords.open(testingPath);
  if(testingWords.fail())
  {
    std::cerr << "List of words to test could not be opened" << '\n';
    return -99;
  }

  std::string currLine;
  while(words >> currLine)
  {
    test->addAWord(currLine);
  }

  while(testingWords >> currLine)
  {
    if(test->isAWord(currLine))
    {
      std::cout << currLine << " is found" << std::endl;
    }
    else
    {
      std::cout << currLine << " is not found, did you mean:" << std::endl;
    }
  }
}
