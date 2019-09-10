#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <iostream>
#include "hpdf.h"

using namespace std;

class HaruPDF
{
private:
  HPDF_Page page;
  HPDF_Doc pdf;
  double _cenX, _cenY;

public:
  void createPDF(double centerX, double centerY)
  {
    _cenX = centerX;
    _cenY = centerY;
    pdf = HPDF_New (NULL, NULL);

    /* add a new page object. */
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    //    print_grid  (pdf, page);
    HPDF_Font font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);

    HPDF_Page_BeginText (page);
    // Their example sets font twice. Probably some kind of mistake. Fix it or do what they do.
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 30);
  }

  void writeChar(char text, float x, float y, float rad1, float rad2, float angle)
  {
    char buf[2];

    // This ugly function defines where any following text will be placed
    // on the page. The cos/sin stuff is actually defining a 2D rotation
    // matrix.
    HPDF_Page_SetTextMatrix(page,
                            cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                            x, y);

    // C-style strings are null-terminated. The last character must a 0.
    buf[0] = text; // The character to display
    buf[1] = 0;
    HPDF_Page_ShowText (page, buf);
  };

  void savePDF()
  {
    char fname[256] = "./spiralPDF.pdf";

    HPDF_Page_EndText (page);

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);
  }

  double getCenX()
  {
    return _cenX;
  }

  double getCenY()
  {
    return _cenY;
  }
};
