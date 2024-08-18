#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *searchBST(node *bst, int val)
{
    if (bst == NULL)
    {
        return NULL;
    }
    node *currnode = bst;
    while (currnode != NULL)
    {
        if (currnode->data == val)
        {
            return currnode;
        }
        else if (currnode->data < val)
        {
            currnode = currnode->left;
        }
        else if (currnode->data > val)
        {
            currnode = currnode->right;
        }
    }
    return currnode;
}

node* insertBST(node *bst, int val)
{
    node *temp, *currnode, *prevnode;
    temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nMalloc failed!\n");
        exit(1);
    }
    temp->data = val;
    // Since addition is done at the leaf position only, hence both the left and right should be NULL
    temp->left = NULL;
    temp->right = NULL;
    if (bst == NULL)
    {
        return temp;
    }
    currnode = prevnode = bst;
    // Attempting failed search
    while (currnode != NULL)
    {
        if (currnode->data == val)
        {
            break;
        }
        else if (currnode->data > val)
        {
            prevnode = currnode;
            currnode = currnode->left;
        }
        else if (currnode->data < val)
        {
            prevnode = currnode;
            currnode = currnode->right;
        }
    }
    //Now currnode is at NULL and prevnode is at just the leaf node
    if (val > prevnode->data)
    {
        prevnode->right = temp;
    }
    else if (val < prevnode->data)
    {
        prevnode->left = temp;
    }
    else
    {
        printf("\nDuplicate values can't be inserted!\n");
    }
    return bst;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}

node* createBST(node *bst)
{
    int value, choice, whether = 1;
    while (whether)
    {
        printf("\nEnter the element you want to insert : ");
        scanf("%d", &value);
        bst = insertBST(bst, value);
        printf("\nDo you want to insert another value? (1 for yes, 0 for no) : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            whether = 1;
        }
        else
        {
            whether = 0;
        }
    }
    return bst;
}

int main()
{
    printf("\nWelcome to BST! Enter the inputs : \n");
    int mode = 1, choice, value;
    node *thenode, *bst = NULL;
    while(mode)
    {
        printf("\nHere are your choices : \n1. Create the BST\n2. Insert into the BST\n3. Inorder traversal\n4. Preorder traversal\n5. Postorder traversal\n6. Search for an element\n7. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                bst = createBST(bst);
                break;
            case 2:
                printf("\nEnter the value you want to insert : ");
                scanf("%d", &value);
                thenode = insertBST(bst, value);
                break;
            case 3:
                inorder(bst);
                break;
            case 4:
                preorder(bst);
                break;
            case 5:
                postorder(bst);
                break;
            case 6:
                printf("\nEnter the value you want to search for : ");
                scanf("%d", &value);
                thenode = searchBST(bst, value);
                if (thenode != NULL)
                {
                    printf("\nThe element has been found in the tree\n");
                }
                else
                {
                    printf("\nThe element has not been found in the tree\n");
                }
                break;
            case 7:
                mode = 0;
                break;
            default : 
                printf("\nEnter a valid input!\n");
                break;
        }
    }
    return 0;
}

// 8 1 3 1 10 1 1 1 6 1 14 1 4 1 7 1 13 0