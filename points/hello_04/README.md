指向函数的指针
============
用于函数间的调用
定义函数指针
```
int (*pmax)(int a, int b) = max;
```

编译
====
gcc -o hello hello.c
./hello