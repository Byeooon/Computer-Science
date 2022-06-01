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

TreeNode* minValueNode(TreeNode* root)
{   //Find a replacement value
    TreeNode* p = root;
    while(p->left != NULL)
        p = p->left;
    return p;
}

TreeNode* deleteNode(TreeNode* root, element key)
{
    if(root == NULL)
        return NULL;
    
    if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else //When I found it
    {
        if(root->left == NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            TreeNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key); 
        }
    }
    return root;
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
    deleteNode(root, 30); preOrder(root); printf("\n");
    deleteNode(root, 26); preOrder(root); printf("\n");
    deleteNode(root, 18); preOrder(root); printf("\n");

}