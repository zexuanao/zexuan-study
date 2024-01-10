#include <stdio.h>
#include <stdlib.h>

typedef struct trnode {
    char data;
    struct trnode* left;
    struct trnode* right;
} Trnode;

// 创建一个新的节点
Trnode* createNode(char data) {
    Trnode* newNode = (Trnode*)malloc(sizeof(Trnode));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// 前序遍历
void PreOrderTraverse(Trnode* T) {
    if (T != NULL) {
        printf("%c ", T->data);
        PreOrderTraverse(T->left);
        PreOrderTraverse(T->right);
    }
}

// 中序遍历
void InOrderTraaverse(Trnode* T) {
    if (T != NULL) {
        InOrderTraaverse(T->left);
        printf("%c ", T->data);
        InOrderTraaverse(T->right);
    }
}

// 后序遍历
void PostOrderTraverse(Trnode* T) {
    if (T != NULL) {
        PostOrderTraverse(T->left);
        PostOrderTraverse(T->right);
        printf("%c ", T->data);
    }
}

// 释放树节点内存
void freeTree(Trnode* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node); // 释放节点内存
    }
}

int main() {
    // 创建二叉树
    Trnode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    root->right->right = createNode('G');

    // 输出前序、中序、后序遍历结果
    printf("PreOrder: ");
    PreOrderTraverse(root);
    printf("\n");

    printf("InOrder: ");
    InOrderTraaverse(root);
    printf("\n");

    printf("PostOrder: ");
    PostOrderTraverse(root);
    printf("\n");

    // 释放树内存
    freeTree(root);

    return 0;
}
