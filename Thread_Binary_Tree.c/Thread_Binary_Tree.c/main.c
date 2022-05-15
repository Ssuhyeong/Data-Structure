#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    char data;
    struct treeNode *left;
    struct treeNode *right;
    int isThreadRight;
}treeNode;

treeNode *makeRootNode(char data, treeNode *leftNode, treeNode *rightNode, int isTreadRight)
{
    treeNode *root = (treeNode*)malloc(sizeof(treeNode));
    root -> data = data;
    root -> left = leftNode;
    root -> right = rightNode;
    root -> isThreadRight = isTreadRight;
    return root;
}

treeNode *findTreadSuccessor(treeNode *p)
{
    treeNode *q = p->right;
    if(q == NULL) return q;
    if(p->isThreadRight == 1) return q;
    while(q -> left != NULL) q = q->left;
    return q;
}

void ThreadInorder(treeNode *root)
{
    treeNode *q;
    q = root;
    while(q->left) q = q->left;
    do
    {
        printf("%3c",q->data);
        q = findTreadSuccessor(q);
    }while(q);
}

int main(void)
{
    treeNode* n7 = makeRootNode('D', NULL, NULL,0);
    treeNode* n6 = makeRootNode('C', NULL, NULL,1);
    treeNode* n5 = makeRootNode('B', NULL, NULL,1);
    treeNode* n4 = makeRootNode('A', NULL, NULL,1);
    treeNode* n3 = makeRootNode('/', n6, n7, 0);
    treeNode* n2 = makeRootNode('*', n4, n5, 0);
    treeNode* n1 = makeRootNode('-', n2, n3, 0);
    
    n4->right = n2;
    n5->right = n1;
    n6->right = n3;
    
    ThreadInorder(n1);
    return 0;
}
