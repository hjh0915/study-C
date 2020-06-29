#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "BSTree.h"

#define LEN_MAX 1000
char buffer[LEN_MAX];


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
    Node_t *pNode = *ppNode; //指向子树根节点的指针
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
                   *key2 = pBST->getKey(pNode->data);
        if (pBST->cmp(key1, key2) < 0)
            return insert(pBST, &(pNode->left), pData, size);
        else
            return insert(pBST, &(pNode->right), pData, size);
    }
}

// 从树中找数据
static const void *search(BST_t *pBST, const Node_t *pNode, const void *pKey);

const void *BST_search(BST_t *pBST, const void *pKey) {
    if (pBST == NULL || pKey == NULL) return NULL;
    return search(pBST, pBST->pRoot, pKey);
}

static const void *search(BST_t *pBST, const Node_t *pNode, const void *pKey) {
    if (pNode == NULL)
        return NULL;
    else
    {
        int cmp_res = pBST->cmp(pKey, pBST->getKey(pNode->data));
        if (cmp_res == 0) 
            return pNode->data;
        else if (cmp_res < 0) 
            return search(pBST, pNode->left, pKey);
        else
            return search(pBST, pNode->right, pKey);
    }
}

// 从树中删除节点
static Node_t *detachMin(Node_t **ppNode) {
    Node_t *pNode = *ppNode;
    if (pNode == NULL) 
        return NULL;
    else if (pNode->left != NULL) 
        return detachMin(&(pNode->left));
    else {
        *ppNode = pNode->right;
        return pNode;
    }
}

static _Bool erase(BST_t *pBST, Node_t **ppNode, const void *pKey);

_Bool BST_erase(BST_t *pBST, const void *pKey) {
    if (pBST == NULL || pKey == NULL) return false;
    return erase(pBST, &(pBST->pRoot), pKey);
}

static _Bool erase(BST_t *pBST, Node_t **ppNode, const void *pKey) {
    Node_t *pNode = *ppNode;
    if (pNode == NULL) 
        return false;
    int cmp_res = pBST->cmp(pKey, pBST->getKey(pNode->data));
    if (cmp_res < 0) 
        return erase(pBST, &(pNode->left), pKey);
    else if (cmp_res > 0) 
        return erase(pBST, &(pNode->right), pKey);
    else {
        if (pNode->left == NULL) 
            *ppNode = pNode->right;
        else if (pNode->right == NULL) 
            *ppNode = pNode->left;
        else {
            Node_t *pMin = detachMin(&(pNode->right));
            *ppNode = pMin;
            pMin->left = pNode->left;
            pMin->right = pNode->right;
        }
        free(pNode);
        return true;
    }
}

static void clear(Node_t *pNode);
void BST_clear(BST_t *pBST) {
    if (pBST != NULL) {
        clear(pBST->pRoot);
        pBST->pRoot = NULL;
    }
}
static void clear(Node_t *pNode) {
    if (pNode != NULL) {
        clear(pNode->left);
        clear(pNode->right);
        free(pNode);
    }
}

// 树中遍历
static int inorder(Node_t *pNode, _Bool (*action)(void *pData));

int BST_inorder(BST_t *pBST, _Bool (*action)(void *pData)) {
    if (pBST == NULL || action == NULL) 
        return 0;
    else 
        return inorder(pBST->pRoot, action);
}

static int inorder(Node_t *pNode, _Bool (*action)(void *pData)) {
    int count = 0;
    if (pNode == NULL) 
        return 0;
    count = inorder(pNode->left, action);
    if (action(pNode->data)) 
        ++count;
    count += inorder(pNode->right, action);
    return count;
}


// 应用
_Bool printStr(void *str) { return printf("%s\n", str) >= 0;}

int main() {
    BST_t *pStrTree = newBST((CmpFunc_t*)strcmp, NULL);
    int n;
    while (fgets(buffer, LEN_MAX, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (!BST_insert(pStrTree, buffer, len+1))
            break;
    }
    if (!feof(stdin)) {
        fprintf(stderr, "sortlines:"
                "Error reading or storing text input.\n");
        exit(EXIT_FAILURE);
    }
    n = BST_inorder(pStrTree, printStr);
    fprintf(stderr, "\nsortlines:Printed %d lines.\n", n);
    BST_clear(pStrTree);
    return 0;
}