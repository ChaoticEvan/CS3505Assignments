#include "Spiral.cpp"

double const centerX = 250.0, centerY = 250.0, startRad = 10.0, startAng = 0.0;

int main (int argc, char **argv)
{
  Spiral spiral(centerX, centerY, startRad, startAng);

  for(int i = 0; i < strlen(argv); i++)
  {
    spiral++;
    spiral.writeChar(argv[i]);
  }

}
