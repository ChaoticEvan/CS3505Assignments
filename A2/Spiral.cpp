#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "HaruPDF.cpp"

using namespace std;

class Spiral
{
private:
  double _cenX, _cenY, radius;
  double textX, textY, textAng;
  float rad1, rad2;
  HaruPDF hp;
public:



  Spiral(double centerX, double centerY, double startRad, double textAng) : _cenX(centerX), _cenY(centerY), radius(startRad), textAng(textAng)
  {
    hp.createPDF(centerX, centerY);
  }

  Spiral& operator++()
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

  Spiral operator++(int i)
  {
    Spiral result(*this);
    ++(*this);
    return *this;
  }

  double getTextX()
  {
    return textX;
  }

  double getTextY()
  {
    return textY;
  }

  double getTextAngle()
  {
    return textAng;
  }

  void writeChar(char c)
  {
    hp.writeChar(c, textX, textY, rad1, rad2, textAng);
  }

  void savePDF()
  {
    hp.savePDF();
  }
};
