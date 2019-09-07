#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <iostream>
#include "hpdf.h"

class HaruPDF
{
private:
  const char* SAMP_TXT = "Hello there. General Kenobi!";
  HPDF_Page page;
  HPDF_Doc pdf;
  double _cenX, _cenY;

public:
  HPDF_Doc createPDF(double centerX, double centerY)
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
    HPDF_Page_SetFontAndSize (page, font, 30);
    return pdf;
  }

  void writeChar(char text)
  {
    float rad1, rad2, angle2;
    // Place characters one at a time on the page.

    char buf[2];
    float x;
    float y;
    // rad1 determines the angle of the letter on the page. rad2 is how far
    // around the circle you are. Notice that they are perpendicular and
    // thus not independent.
    //
    // Pay careful attention to what wants radians and what is degrees
    // between haru and spiral and math functions.
    rad1 = (angle2 - 90) / 180 * 3.141592;
    rad2 = angle2 / 180 * 3.141592;

    // The position of the character depends on the center point
    // plus the angle and the radius.
    x = 210 + cos(rad2) * 150;
    y = 300 + sin(rad2) * 150;

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
    angle2 -= 10.0; // change the angle around the circle

  };

  void savePDF(char fname[])
  {
    HPDF_Page_EndText (page);

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);
  }
};
