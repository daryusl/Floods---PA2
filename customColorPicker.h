#ifndef CUSTOMCOLORPICKER_H
#define CUSTOMCOLORPICKER_H

#include "colorPicker.h"

class customColorPicker : public colorPicker
{
  public:

    customColorPicker(HSLAPixel fillColor, int customSpacing);

    virtual HSLAPixel operator()(int x, int y);

  private:
    HSLAPixel color; 
    int spacing;     
};

#endif
