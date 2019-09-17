#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <iostream>
#include "hpdf.h"
 
#ifndef HARU_PDF_H
#define HARU_PDF_H
class HaruPDF
{
private:
  HPDF_Page page;
  HPDF_Doc pdf;
  double _cenX, _cenY;

public:
  void createPDF(double centerX, double centerY);
  void writeChar(char text, float x, float y, float rad1, float angle);
  void savePDF();
  double getCenX();
  double getCenY();
};
#endif /* end of include guard: HARU_PDF_H */
