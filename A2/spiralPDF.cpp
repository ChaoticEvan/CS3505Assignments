#include "Spiral.cpp"
using namespace std;

double const centerX = 210.0, centerY = 300.0, startRad = 100.0, startAng = 0.0;

int main (int argc, char *argv[])
{
  if(argc == 1)
  {
    std:cerr << "No argument provided." << std::endl;
    return -99;
  }

  Spiral spiral(centerX, centerY, startRad, startAng);

  for(int i = 0; argv[1][i] != '\0'; i++)
  {
    char letter = argv[1][i];

    spiral++;
    spiral.writeChar(letter);
  }

  spiral.savePDF();

  return -99;
}
