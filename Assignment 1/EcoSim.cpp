#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);
void runSimulation(int iterations, double rabbits, double foxes);
void plotCharacter(int number, char c);
void plotPopulations(double numOfRabbits, double numOfFoxes, double factor);

int main()
{
  double rabbitPop;
  double foxPop;

  /* Gets the population for both rabbits and foxes
  and error checks them*/
  std::cout << "What is the initial rabbit population?: " << std::endl;
  if (!(cin >> rabbitPop))
  {
    std::cerr << "ERROR: Rabbit population could not be converted to double" << endl;
    return 0;
  }
  std::cout << "What is the initial fox population?: " << std::endl;
  if (!(cin >> foxPop))
  {
    std::cerr << "ERROR: Fox population could not be converted to double" << endl;
    return 0;
  }

  // Run the equation as specified in the assignment
  runSimulation(500, rabbitPop, foxPop);
}


void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes)
{

}

void runSimulation(int iterations, double rabbits, double foxes)
{

}

void plotCharacter(int number, char c)
{
  for(int i = 1; i < number; i++)
  {
    std::cout << " ";
  }

  std::cout << c;
}

void plotPopulations(double numOfRabbits, double numOfFoxes, double factor)
{
  if(numOfRabbits < numOfFoxes)
  {
    plotCharacter(numOfRabbits * factor + 1, 'r');
    plotCharacter(((numOfFoxes - numOfRabbits) * factor) + 1, 'F');
  }
  else
  {
    plotCharacter(numOfFoxes * factor + 1, 'F');
    plotCharacter(((numOfRabbits - numOfFoxes) * factor) + 1, 'r');
  }

  std::cout << endl;
}


void incrementCounter()
