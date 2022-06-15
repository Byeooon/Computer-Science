#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct  TreeNode
{
    element key;
    struct TreeNode* left,* right;
}TreeNode;

TreeNode* insertNode(TreeNode* root, element key)
{
    if(root == NULL)
    {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if(key < root->key)
        root->left = insertNode(root->left, key);
    else if(key > root->key)
        root->right = insertNode(root->right, key);

    return root;
} 

void preOrder(TreeNode* root) //VLR
{
    if(root)
    {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode* root) //LVR
{
    if(root)
    {   
        inOrder(root->left);
        printf("[%d] ", root->key);
        inOrder(root->right);
    }
}

void postOrder(TreeNode* root) //LRV
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ", root->key);
    }
}

int main()
{
    TreeNode* root = NULL;

    root = insertNode(root, 35);
    root = insertNode(root, 68);
    root = insertNode(root, 99);
    root = insertNode(root, 18);
    root = insertNode(root, 7);
    root = insertNode(root, 3);
    root = insertNode(root, 12);
    root = insertNode(root, 26);
    root = insertNode(root, 22);
    root = insertNode(root, 30);

    preOrder(root); printf("\n");
    inOrder(root); printf("\n");
    postOrder(root); printf("\n");
}
