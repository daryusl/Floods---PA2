#include "customColorPicker.h"

customColorPicker::customColorPicker(HSLAPixel fillColor, int customSpacing)
{
    color = fillColor;
    spacing = customSpacing;
}

HSLAPixel customColorPicker::operator()(int x, int y)
{
    if(x%spacing == 0){
        return color;
    }
    if(y%spacing == 0) {
        return color;
    }
    else{
        return HSLAPixel(0,0,1.0);
    }
}
