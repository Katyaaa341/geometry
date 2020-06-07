#include "ctest.h"
#include "check_radius.h"
#include "crossing.h"
#include "name_of_figure.h"

CTEST(checkName, circle)
{
    char *figure = "circle";
    int value = nameFigure(figure);
    ASSERT_EQUAL(0, value);
    char *figure2 = "";
    value = nameFigure(figure2);
    ASSERT_EQUAL(1, value);
    char *figure3 = "aposdfh";
    value = nameFigure(figure3);
    ASSERT_EQUAL(1, value);
    char *figure4 = "   ";
    value = nameFigure(figure4);
    ASSERT_EQUAL(1, value);
    char *figure5 = "9183274";
    value = nameFigure(figure5);
    ASSERT_EQUAL(1, value);
}

CTEST(checkRadius, radius)
{
    int value = checkRadius(1);
    ASSERT_EQUAL(0, value);
    value = checkRadius(0);
    ASSERT_EQUAL(1, value);
    value = checkRadius(-1);
    ASSERT_EQUAL(1, value);
}

CTEST(checkCrossing, crossing)
{
    int value = crossing(1, 2, 3, 4, 5, 6);
    ASSERT_EQUAL(0, value);
    value = crossing(0, 0, 0, 0, 1, 3);
    ASSERT_EQUAL(1, value);
}
