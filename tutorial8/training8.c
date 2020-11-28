/* Tutorial 8 using typedef */

#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

Point makePoint(int xx, int yy)
{
    Point p;
    p.x = xx;
    p.y = yy;

    return p;
}

int main()
{
    Point myPoint2 = makePoint(3, 5);
    printf("myPoint2.x = %d myPoint2.y = %d\n", myPoint2.x, myPoint2.y);
    return 0;
}