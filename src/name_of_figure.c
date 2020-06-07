#include <string.h>

int nameFigure(char* figure)
{
    if (strncmp(figure, "circle", 6) == 0) {
        return 0;
    }
    return 1;
}
