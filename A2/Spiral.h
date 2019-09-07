#include "hpdf.h"
#include "HaruPDF.h"

class Spiral{
private:
  double _cenX, _cenY, _startRad, _startAng;
  double textX, textY, textAng;
  HPDF_Doc pdf;
public:
  Spiral(double centerX, double centerY, double startRad, double startAng);
  Spiral& operator++();
  double getX();
  double getY();
  double gettextAngle();
};
