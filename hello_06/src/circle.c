#include <stdio.h>
#include "./utils/my.h"

int main() {
    double r = 2.0, area = 0.0;
    area = circularArea(r);

    printf("半径: %10.1f, 面积: %10.2f\n", r, area);
    
    return 0;
}