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

int getNodeCount(TreeNode* node)
{
    int count = 0;
    
    if(node != NULL)
        count = 1 + getNodeCount(node->left) + getNodeCount(node->right);

    return count;
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

    printf("%d \n", getNodeCount(root));
}