#include <stdio.h>
#include <string.h>

typedef struct Node {
    struct Node *left, *right; //指向左边、右边的子节点
    size_t size; //数据空间大小
    char data[]; //数据本身
} Node_t;

typedef const void *GetKeyFunc_t(const void *dData);
typedef int CmpFunc_t (const void *pKey1, const void *pKey2);

typedef struct {
    struct Node *pRoot; //指向根的指针
    CmpFunc_t *cmp; //比较两个键值
    GetKeyFunc_t *getKey; //将数据转换成键值
}