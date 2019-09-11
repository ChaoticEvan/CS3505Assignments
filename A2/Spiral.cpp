/* File for plotting text on the pdf in the
   spiral pattern.

   By: Evan Voordeckers | u1087559 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "Spiral.h"
#include "HaruPDF.cpp"
/* Spiral class used for computing the
 X and Y coordinates and angle of each
character for the spiral */
double _cenX, _cenY, radius;
double textX, textY, textAng;
float rad1, rad2;
HaruPDF hp;

/* constructs a spiral object with
   the given center x and y coordinates,
   the starting radius, and the starting text
   angle */
Spiral::Spiral(double centerX, double centerY, double startRad, double textAng) : _cenX(centerX), _cenY(centerY), radius(startRad), textAng(textAng)
{
  hp.createPDF(centerX, centerY);
  textX = startRad;
}

/* increments the spiral's
   coordinates and angles
   for the next character to be plooted */
Spiral& Spiral::operator++()
{
  rad1 = (textAng - 90) / 180 * 3.141592;
  rad2 = textAng / 180 * 3.141592;

  // The position of the character depends on the center point

  // plus the angle and the radius.
  textX = hp.getCenX() + cos(rad2) * radius;
  textY = hp.getCenY() + sin(rad2) * radius;

  textAng -= 10;
  radius += 1.0;

  return *this;
}

/* increments the spiral's
   coordinates and angles
   for the next character to be plooted */
Spiral Spiral::operator++(int i)
{
  Spiral result(*this);
  ++(*this);
  return result;
}

/* helper methods for calling
   methods contained in our
   facade file */
void Spiral::writeChar(char c)
{
  hp.writeChar(c, textX, textY, rad1, textAng);
}
void Spiral::savePDF()
{
  hp.savePDF();
}

// Getters for spiral's coordinates and angle
double Spiral::getTextX()
{
  return textX;
}
double Spiral::getTextY()
{
  return textY;
}
double Spiral::getTextAngle()
{
  return textAng;
}
