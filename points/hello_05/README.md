结构体
=====
typedef struct tag { 
    member-list
    member-list 
    member-list  
    ...
} variable-list;

链表
====
创建节点
----------
``` c
List *create_node(int num) 
```

释放链表
----------
``` c
void Free_list(List *head)
```

malloc函数
==========
分配长度为num_bytes字节的内存块
如果分配成功则返回指向被分配内存的指针，否则返回空指针NULL。

memset函数
==========
``` c   
#include <string.h>
memset(void *str, int c, size_t n)
```
str -- 指向要填充的内存块。
c -- 要被设置的值。该值以 int 形式传递，但是函数在填充内存块时是使用该值的无符号字符形式。
n -- 要被设置为该值的字节数。

编译
====
gcc -o hello hello.c
./hello