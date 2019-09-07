class spiral
{
private:
  double _cenX, _cenY, _startRad, _startAng;
  double textX, textY, textAng;
  HPDF_Doc pdf;
public:
  spiral(double centerX, double centerY, double startRad, double startAng) : _cenX(centerX), _cenY(centerY), _startRad(startRad), _startAng(startAng)
  {
    pdf = createPDF(centerX, centerY);

  }

  spiral& operator++()
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
};

int main()
{
  return -99;
}
