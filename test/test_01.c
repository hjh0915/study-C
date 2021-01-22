#include <stdio.h>
void Func(int x) {
    x = 20;
}
int main(void) {
    int x = 10;
    Func(x);
    printf("%d", x);
    return 0;
}