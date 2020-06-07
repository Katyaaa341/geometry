#include <stdlib.h>
#include <math.h>

int crossing(int x1, int y1, int x2, int y2, int r1, int r2)
{
    float d = sqrt(pow((float)(x2 - x1), 2) +
                   pow((float)(y2 - y1), 2));
    if ((d == 0 && r1 == r2) || (d > (float)(r1 + r2)) ||
        (d < abs(r1 - r2))) {
        return 1;
    }
    return 0;
}