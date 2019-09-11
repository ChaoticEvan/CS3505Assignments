/* File for generating a pdf with a spial of
 text provided via command line arguments

 By: Evan Voordeckers | u1087559 */

#include "Spiral.h"
using namespace std;
double const centerX = 210.0, centerY = 300.0, startRad = 100.0, startAng = 0.0;

/* Method that creates a file "spiralPDF.pdf"
   with a spiral of the text given as a command
   line paramter */
int main (int argc, char *argv[])
{
  // Error checking
  if(argc == 1)
  {
    std::cerr << "No argument provided." << std::endl;
    return -99;
  }

  // Create spiral obj and write each char
  Spiral spiral(centerX, centerY, startRad, startAng);
  for(int i = 0; argv[1][i] != '\0'; i++)
  {
    char letter = argv[1][i];

    spiral++;
    spiral.writeChar(letter);
  }

  // Finally, save the PDF
  spiral.savePDF();
  return -99;
}
