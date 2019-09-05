#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(HSLAPixel fillColor, PNG &img, double tolerance, HSLAPixel center)
{
    color = fillColor;
    tol = tolerance;
    im = img;
    ctr = center;
}

HSLAPixel borderColorPicker::operator()(int x, int y)
{

    for (int a = x - 3; a <= x + 3; a++)
    {
        for (int b = y - 3; b <= y + 3; b++)
        {
            if (a < im.width() && b < im.height() && a >= 0 && b >= 0)
            {
                HSLAPixel *curr = im.getPixel(a, b);

                int xDist = (x - a);
                int yDist = (y - b);
                int distance = (xDist * xDist) + (yDist * yDist);

                if (distance <= 9)
                {
                    if (curr->dist(ctr) > tol)
                    {
                        return color;
                    }
                }
            }
            else
            {
                return color;
            }
        }
    }
    return *im.getPixel(x, y);
}