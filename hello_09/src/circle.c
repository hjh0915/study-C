#include <stdio.h>
#include "my.h"

int main() {
    double radius = 1.0, area = 0.0;
    area = circularArea(radius);

    printf("半径: %10.1f, 面积: %10.2f\n", radius, area);
    
    return 0;
}
