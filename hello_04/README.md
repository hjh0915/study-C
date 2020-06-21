编译
===
因为使用了数学函数atan()，所以需要#include <math.h>

gcc -c circle.c
gcc -c circulararea.c
gcc -o circle circle.o circulararea.o -lm