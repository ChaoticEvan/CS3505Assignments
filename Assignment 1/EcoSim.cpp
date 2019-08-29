/*
  This app runs a simulation based on a given starting population number
  of foxes and rabbits. Then prints out results in a graph.
  Written by Evan Voordeckers. UID: u1087559
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);
void runSimulation(int iterations, double rabbits, double foxes);
void plotCharacter(int number, char c);
void plotPopulations(double numOfRabbits, double numOfFoxes, double factor);
int& incrementCounter(int& counter);

/*
  Main entry point for the program that gets the initial population
  numbers for running the simulation.
*/
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


/*
  Update population numbers based on formulas given in the assignment
*/
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes)
{
  double rabbitChange = g * numRabbits * (1 - numRabbits/K) - p * numRabbits * numFoxes;
  double foxChange = c * p * numRabbits * numFoxes - m * numFoxes;

  numRabbits += rabbitChange;
  numFoxes += foxChange;
}

/*
  Runs the simulation based with the given amount of iterations
*/
void runSimulation(int iterations, double rabbits, double foxes)
{
  plotPopulations(rabbits, foxes, 0.1);

  // Loop through iterations and update/print the population numbers.
  int i = iterations;
  for (i; i > 0; i--)
  {
    updatePopulations(0.2, 0.0022, 0.6, 0.2, 1000.0, rabbits, foxes);

    // Error checking
    if(rabbits < 0 || foxes < 0)
    {
      std::cerr << "ERROR: Did not finish graph. Rabbit or fox population dropped below 0" << '\n';
      return;
    }

    plotPopulations(rabbits, foxes, 0.1);
  }
}

/*
  Prints out the given character after printing the
  given number of spaces
*/
void plotCharacter(int number, char c)
{
  for(int i = 1; i < number; incrementCounter(i))
  {
    std::cout << " ";
  }

  std::cout << c;
}

/*
  Plots the population of given number of rabbits and
  foxes. Multiplies the pop numbers by the factor given.
*/
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


/*
  Counter incrementer for practiving pass by reference
  as opposed to pass by value
*/
int& incrementCounter(int& counter)
{
  counter += 1;
}
