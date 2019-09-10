#include "hpdf.h"
#include "HaruPDF.h"

class Spiral{
private:
  double _cenX, _cenY, radius;
  double textX, textY, textAng;
  float rad1, rad2;
  HaruPDF hp;
public:
  Spiral(double centerX, double centerY, double startRad, double textAng);
  Spiral& operator++();
  double getX();
  double getY();
  double gettextAngle();
  void writeChar(char c);
  void savePDF();
};
