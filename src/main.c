#include <stdio.h>
#include "name_of_figure.h"
#include "check_radius.h"
#include "crossing.h"

int main()
{
    float pi = 3.14f;
    int x1, x2, y1, y2, r1, r2;
    float p1, p2, s1, s2;
    char figure[50];
    printf("Доступные фигуры: circle\n");
    printf("Введите название фигуры - ");
    scanf("%s", figure);
    int value = nameFigure(figure);
    if (value == 1) {
        printf("Ошибка ввода");
        return 0;
    } else {
        printf("Введите координаты I окружности  - ");
        if (scanf("%d", &x1) != 1) {
            printf("\nЗначение координат должно быть целым");
            return 0;
        }
        if (scanf("%d", &y1) != 1) {
            printf("\nЗначение координат должно быть целым");
            return 0;
        }
        printf("\nВведите радиус - ");
        scanf("%d", &r1);
        int value_2 = checkRadius(r1);
        if (value_2 == 1) {
            printf("Радиус должен быть больше нуля");
            return 0;
        }
        s1 = pi * (float)r1 * (float)r1;
        p1 = 2 * pi * (float)r1;



        printf("Введите координаты I окружности  - ");
        if (scanf("%d", &x2) != 1) {
            printf("\nЗначение координат должно быть целым");
            return 0;
        }
        if (scanf("%d", &y2) != 1) {
            printf("\nЗначение координат должно быть целым");
            return 0;
        }
        printf("\nВведите радиус - ");
        scanf("%d", &r2);
        int value_3 = checkRadius(r2);
        if (value_3 == 1) {
            printf("Радиус должен быть больше нуля");
            return 0;
        }
        s2 = pi * (float)r2 * (float)r2;
        p2 = 2 * pi * (float)r2;
        int getInter = crossing(x1, y1, x2, y2, r1, r2);
        if (getInter == 0) {
            printf("\nОкружности пересекаются\n");
        } else {
            printf("\nОкружности не пересекаются\n");
        }
        printf("Площадь I окружности: %0.2f\n", s1);
        printf("Периметр I окружности: %0.2f\n\n", p1);
        printf("Площадь II окружности: %0.2f\n", s2);
        printf("Периметр II окружности: %0.2f\n", p2);
    }
    return 0;
}
