#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(TreeNode **root, int value)
{
    if (*root == NULL)
    {
        *root = createNode(value);
    }
    else
    {
        if (value < (*root)->value)
        {
            insert(&((*root)->left), value);
        }
        else if (value > (*root)->value)
        {
            insert(&((*root)->right), value);
        }
    }
}

void inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

int main()
{
    TreeNode *root = NULL;

    printf("Enter integers to insert into the binary search tree.\nEnter -1 to finish.\n");
    int value;
    while (1)
    {
      //  printf("Enter an integer or -1 to finish: ");
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        insert(&root, value);
    }

    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");

    // Free memory
    // TODO: Implement a function to free the memory allocated for the tree nodes

    return 0;
}
