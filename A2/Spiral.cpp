#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"
#include "HaruPDF.cpp"

class Spiral
{
private:
  double _cenX, _cenY, _startRad, _startAng;
  double textX, textY, textAng;
  HPDF_Doc pdf;
  HaruPDF hp;
public:
  Spiral(double centerX, double centerY, double startRad, double startAng) : _cenX(centerX), _cenY(centerY), _startRad(startRad), _startAng(startAng)
  {
    pdf = hp.createPDF(centerX, centerY);
  }

  Spiral& operator++(int i)
  {
    return *this;
  }

  double getX()
  {
    return textX;
  }

  double getY()
  {
    return textY;
  }

  double gettextAngle()
  {
    return textAng;
  }

  void writeChar(char* c)
  {
    hp.writeChar(c);
  }
};
