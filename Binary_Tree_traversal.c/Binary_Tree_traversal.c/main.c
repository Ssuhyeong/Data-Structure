#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    char data;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode* makeRootNode(char data, treeNode *leftNode, treeNode *rightNode)
{
    treeNode *root = (treeNode*)malloc(sizeof(treeNode));
    root -> data = data;
    root -> left = leftNode;
    root -> right = rightNode;
    return root;
}

void Preorder(treeNode *root)
{
    if(root)
    {
        printf("%c",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(treeNode *root)
{
    if(root)
    {
        Inorder(root->left);
        printf("%c", root->data);
        Inorder(root->right);
    }
}

void Postorder(treeNode *root)
{
    if(root)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%c", root->data);
    }
}

int main(void)
{
    treeNode* n7 = makeRootNode('D', NULL, NULL);
    treeNode* n6 = makeRootNode('C', NULL, NULL);
    treeNode* n5 = makeRootNode('B', NULL, NULL);
    treeNode* n4 = makeRootNode('A', NULL, NULL);
    treeNode* n3 = makeRootNode('/', n6, n7);
    treeNode* n2 = makeRootNode('*', n4, n5);
    treeNode* n1 = makeRootNode('-', n2, n3);
    
    Preorder(n1);
    Inorder(n1);
    Postorder(n1);
    return 0;
}
