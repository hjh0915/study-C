#include <stdio.h>
#include "my.h"
#include <string.h>

int main() {
    int n, m = 0;
    char s[] = "hello world!";
    char *s2 = "hello world!";
    n = length(s);
    m = length(s2);

    printf("%d\n", n);
    printf("%d\n", m);

    printf("%ld\n", strlen(s));
    return 0;
}