#ifndef SPIRAL_H
#define SPIRAL_H
class Spiral{
private:
  double _cenX, _cenY, radius;
  double textX, textY, textAng;
  float rad1, rad2;
  HaruPDF hp;
public:
  Spiral(double centerX, double centerY, double startRad, double textAng);
  Spiral& operator++();
  Spiral operator++(int i);
  double getTextX();
  double getTextY();
  double getTextAngle();
  void writeChar(char c);
  void savePDF();
};
#endif
