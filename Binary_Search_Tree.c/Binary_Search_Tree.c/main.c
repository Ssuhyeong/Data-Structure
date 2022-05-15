#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treeNode{
    char key;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode *searchBST(treeNode* root, char x)
{
    treeNode *p;
    p = root;
    while(p != NULL)
    {
        if(p->key>x) p = p->left;
        else if(x == p->key) return p;
        else    p = p->right;
    }
    
    printf("찾는 키가 없습니다.");
    return p;
}

treeNode *insertNode(treeNode *p, char x)
{
    treeNode *newNode;
    if(p == NULL)
    {
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode -> key = x;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }
    
    else if(x < p->key) p->left == insertNode(p->left, x);
}
