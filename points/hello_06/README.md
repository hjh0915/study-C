stdlib.h
========
若要使用exit需要引入
``` c
#include <stdlib.h>
```
exit(EXIT_FAILURE);
代表异常退出。
exit(EXIT_SUCCESS);
代表安全退出。

stdbool.h
=========
若要使用bool返回需要引入
``` c
#include <stdbool.h>
```
return false;
return true;

memcpy函数
=========
复制内存

头部文件
=======
typedef struct和原型函数需要写在一起，都放在 BSTree.h 中

编译
====
gcc -o sortlines BSTree.c
./sortlines < demo.txt