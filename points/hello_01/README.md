编译
====
gcc -c hello.c
gcc -c length.c
gcc -o hello hello.o length.o

gcc -o hello hello.c length.c

利用数组计算长度
=============
``` c
int length(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n ++;
    return n;
}
```

其中，s++为指针相加

调用字符串函数
============
``` c
#include <string.h>
printf("%ld\n", strlen(s));
```