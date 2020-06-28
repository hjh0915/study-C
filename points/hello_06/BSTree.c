#include <stdio.h>
#include <string.h>

// 创建空树
const void *defaultGetKey(const void *pData) {return pData;}

BST_t *newBST(CmpFunc_t *cmp, GetKeyFunc_t *getKey) {
    BST_t *pBST = NULL;
    if (cmp != NULL) 
        pBST = malloc(sizeof(BST_t));
    if (pBST != NULL) {
        pBST->pRoot = NULL;
        pBST->cmp = cmp;
        pBST->getKey = (getKey!=NULL) ? getKey : defaultGetKey;
    }
    return pBST;
}

// 插入新的节点
static _Bool insert(BST_t *pBST, Node_t **ppNode, const void *pData, size_t size);

_Bool BST_insert(BST_t *pBST, const void *pData, size_t size) {
    if (pBST == NULL || pData == NULL || size == 0) 
        return false;
    return insert(pBST, &(pBST->pRoot), pData, size);
}

static _Bool insert(BST_t *pBST, Node_t **ppNode, const void *pData, size_t size) {
    Node_t *pNode = **ppNode; //指向子树根节点的指针
    if (pNode == NULL) {
        pNode = malloc(sizeof(Node_t) + size);
        if (pNode != NULL) {
            memcpy(pNode->data, pData, size);
            *ppNode = pNode;
            return true;
        }
        else 
            return false;
    }
    else {
        const void *key1 = pBST->getKey(pData),
                   *key2 = pBST->getKey(pNode->pData);
        if (pBST->cmp(key1, key2) < 0)
            return insert(pBST, &(pNode->left), pData, size);
        else
            return insert(pBST, &(pNode->right), pData, size);
    }
}