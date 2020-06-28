#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;

} List;

// 创建节点
List *create_node(int num) {
    List *node = NULL;
    node = (List *)malloc(sizeof(List));
    if(node == NULL){
        printf("malloc error!\n");
    }
    memset(node, 0, sizeof(List));
    node -> data = num;
    node -> next = NULL;
    return node;
}

// 释放链表
void Free_list(List *head) {
    List *freeNode;
    while (NULL != head){
        freeNode = head;
        head = head -> next;
        free(freeNode);
    }
    return;
}

int main() {
    int num = 0;
    List *node_head = create_node(num);
    List *pNode = node_head;

    for(int i = 0; i < 100; i++){
        int num2 = num + i * 2;
        List *node_middle = create_node(num2);
        pNode -> next = node_middle;
        pNode = node_middle;
    }

    pNode -> next = NULL;

    pNode = node_head;
    // 遍历链表
    while (pNode != NULL){
        printf("pNode -> data = %d\n",pNode -> data);
        printf("pNode -> next = %p\n",pNode -> next);

        pNode = pNode -> next;
    }


    Free_list(node_head);
    return 0;
}