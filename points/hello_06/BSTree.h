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
} BST_t;

BST_t *newBST( CmpFunc_t *cmp, GetKeyFunc_t *getKey );
_Bool BST_insert(BST_t *pBST, const void *pData, size_t size);
const void *BST_search(BST_t *pBST, const void *pKey);
_Bool BST_erase(BST_t *pBST, const void *pKey);
void BST_clear(BST_t *pBST);
int BST_inorder(BST_t *pBST, _Bool (*action)(void *pData));
int BST_rev_inorder(BST_t *pBST, _Bool (*action)(void *pData));
int BST_preorder(BST_t *pBST, _Bool (*action)(void *pData));
int BST_postorder(BST_t *pBST, _Bool (*action)(void *pData));