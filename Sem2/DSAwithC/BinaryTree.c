#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

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

node *copier(node *root)
{
    if (root != NULL)
    {
        node *root2;
        root2 = (node *)malloc(sizeof(node));
        root2->data = root->data;
        root2->left = copier(root->left);
        root2->right = copier(root->right);
        return root2;
    }
    else
    {
        return NULL;
    }
}

int findmax(node *root)
{
    if (root == NULL)
    {
        return -1; // Assuming only positive values in the tree
    }
    else
    {
        int leftmax, rightmax, max;
        leftmax = findmax(root->left);
        rightmax = findmax(root->right);
        max = (leftmax > rightmax ? leftmax : rightmax);
        if (max > root->data)
        {
            return max;
        }
        else
        {
            return (root->data);
        }
    }
}

int findmin(node *root)
{
    if (root == NULL)
    {
        return -1; // Assuming only positive values in the tree
    }
    else
    {
        int leftmin, rightmin, min;
        leftmin = findmin(root->left);
        rightmin = findmin(root->right);
        min = (leftmin < rightmin ? leftmin : rightmin);
        if (min < root->data)
        {
            return min;
        }
        else
        {
            return (root->data);
        }
    }
}

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftnum, rightnum;
        leftnum = count(root->left);
        rightnum = count(root->right);
        return (rightnum + leftnum + 1);
    }
}

int findheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftheight, rightheight, max;
        leftheight = findheight(root->left);
        rightheight = findheight(root->right);
        max = (leftheight > rightheight ? leftheight : rightheight);
        return (max + 1);
    }
}

int equal(node *root1, node *root2)
{
    if (root1 != NULL && root2 != NULL)
    {
        int equalleft, equalright;
        equalleft = equal(root1->left, root2->left);
        equalright = equal(root1->right, root2->right);
        if ((root1->data == root2->data) && (equalleft == 1) && (equalright == 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insertq(node* arr[], int *front, int *rear, int MAX, node *thenode) 
{
    if ((((*rear) + 1)%(MAX)) == (*front))
    {
        printf("\nQueue Overflow Encountered!\n");
    }
    else
    {
        (*rear) = ((*rear) + 1 )%(MAX);
        arr[(*rear)] = thenode;
    }
}

node* deleteq(node* arr[], int *front, int *rear, int MAX)
{
    if ((*front) == (*rear))
    {
        printf("\nQueue underflow encountered!\n");
        return NULL;
    }
    else
    {
        (*front) = ((*front) + 1)%(MAX);
        return arr[(*front)];
    }
}

int isqempty(int front, int rear)
{
    if ((front) + 1 == (rear))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

node *searchfor(node *root, int val)
{
    if (root != NULL)
    {
        if (root->data == val)
        {
            return root;
        }
        else
        {
            node *locationleft, *locationright;
            locationleft = searchfor(root->left, val);
            locationright = searchfor(root->right, val);
            if (locationright == NULL && locationleft == NULL)
            {
                return NULL;
            }
            else if (locationleft != NULL)
            {
                return locationleft;
            }
            else
            {
                return locationright;
            }
        }
    }
    else
    {
        return NULL;
    }
}

int countleaves(node *root)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            int leavesleft, leavesright;
            leavesleft = countleaves(root->left);
            leavesright = countleaves(root->right);
            return (leavesright + leavesleft);
        }
    }
}

node *mirror(node *root)
{
    if (root != NULL)
    {
        node *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
    }
}

void lot(node *root)
{
    int MAX = 100;
    node* queue[MAX];
    int front = 0, rear = 0;
    //Above part made an array
    insertq(queue, &front, &rear, MAX, root);
    insertq(queue, &front, &rear, MAX, NULL);  
    node *currentnode;      
    while (!(isqempty(front, rear)))
    {
        currentnode = deleteq(queue, &front, &rear, MAX);
        if (currentnode == NULL)
        {
            printf("\n");
            insertq(queue, &front, &rear, MAX, NULL);        
        }
        else
        {
        printf("%d ", currentnode->data);    
        if (currentnode->left != NULL)
        {
            insertq(queue, &front, &rear, MAX, currentnode->left);
        }
        if (currentnode->right != NULL)
        {
            insertq(queue, &front, &rear, MAX, currentnode->right);
        }
        }
    }
}

void createe(node **root) //Data is entered unless -1 is given
{
    int var;
    scanf("%d", &var);
    if (var == -1)
    {
        *root = NULL;
    }
    else
    {
        (*root) = (node*)malloc(sizeof(node));
        (*root)->data = var;
        printf("\nEnter the left node of %d\n", var);
        createe(&((*root)->left));
        printf("\nEnter the right side of %d\n" ,var);
        createe(&((*root)->right));
    }
}

node *create() // Here data is entered one by one
{
    node *root;
    int left, right;
    root = (node *)malloc(sizeof(node));
    if (root == NULL)
    {
        printf("Malloc failed!");
        exit(1);
    }
    else
    {
        printf("\nEnter the data for the root : ");
        scanf("%d", &root->data);
        fflush(stdin);
        printf("\nDo you want a left subtree? (1 for yes, 0 for no) : ");
        scanf("%d", &left);
        fflush(stdin);
        if (left == 1)
        {
            root->left = create();
        }
        else
        {
            root->left = NULL;
        }
        printf("\nDo you want a right subtree? (1 for yes, 0 for no) : ");
        scanf("%d", &right);
        fflush(stdin);
        if (right == 1)
        {
            root->right = create();
        }
        else
        {
            root->right = NULL;
        }
        return root;
    }
}

node* createee(node *parent, int side) //Which side is also passed, 0 for left and 1 for right
{
    node *root;
    int val, choice;
    if (parent == NULL)
    {
        printf("\nEnter the value of the root node : ");
    }
    else if (side == 0)
    {
        printf("\nEnter the value of the left child of %d : ", parent->data);
    }
    else if (side == 1)
    {
        printf("\nEnter the value of the right child of %d : ", parent->data);
    }
    root = (node*)malloc(sizeof(node));
    scanf("%d", &(root->data));
    printf("\nDoes the node %d have a left child? (0 for no, 1 for yes) : ", root->data);
    scanf("%d", &choice);
    if (choice == 1)
    {
        root->left = createee(root, 0);
    }
    else
    {
        root->left = NULL;
    }
    printf("\nDoes the node %d have a right child? (0 for no, 1 for yes) : ", root->data);
    scanf("%d", &choice);
    if (choice == 1)
    {
        root->right = createee(root, 1);
    }
    else
    {
        root->right = NULL;
    }
    return root;
}

void main()
{
    node *treeroot1 = NULL, *faketreeroot1, *treeroot2 = NULL, *root2, *found, *mirrortreeroot;
    printf("\nWelcome to the binary tree!\n\nWe'll take care of everything, just sitback and enter the inputs :)\n");
    int choice, mode = 1, further;
    while (mode)
    {
        printf("\nHere are your options : \n1. Create the binary tree\n2. Preorder traversal\n3. Postorder traversal\n4. Inorder traversal\n5. Make a copy of the created tree and show its three traversals\n6. Find the maximum node and the minimum node in the tree\n7. Find the number of nodes in the tree\n8. Find the height of the tree\n9. Find a reqired node in the tree\n10. Count leaf nodes\n11. Count non-leaf nodes\n12. Create another tree and check whether it is equal to the tree created previously\n13. Generate the mirror image of the tree by first making a copy of it\n14. Traverse the tree in a level order manner\n15. Exit\n\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nChoose the method by which you want to create your binary tree : create1, create2 or create3 (Enter the number 1, 2 or 3) : ");
            scanf("%d", &further);
            switch (further)
            {
                case 1:
                    treeroot1 = create();
                    break;
                case 2:
                    createe(&treeroot1);
                    break;
                case 3:
                    treeroot1 = createee(treeroot1, 0);
                    break;
                default: 
                    printf("\nEnter a valid input!\n");
                    break;
            }
            break;
        case 2:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                printf("\nThe inorder traversal is : ");
                inorder(treeroot1);
            }
            break;
        case 3:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                printf("\nThe preorder traversal is : ");
                preorder(treeroot1);
            }
            break;
        case 4:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                printf("\nThe postorder traversal is : ");
                postorder(treeroot1);
            }
            break;
        case 5:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                faketreeroot1 = copier(treeroot1);
                printf("\nThe inorder traversal is : ");
                inorder(faketreeroot1);
                printf("\nThe preorder traversal is : ");
                preorder(faketreeroot1);
                printf("\nThe postorder traversal is : ");
                postorder(faketreeroot1);
            }
            break;
        case 6:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                printf("\n\nThe maximum node in the tree is : %d\nThe minimum node in the tree is : %d\n", findmax(treeroot1), findmin(treeroot1));
            }
            break;
        case 7:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                printf("\nThe number of nodes in the binary tree is : %d\n\n", count(treeroot1));
            }
            break;
        case 8:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                printf("\nThe height of the tree is : %d\n", findheight(treeroot1));
            }
            break;
        case 9:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                int number;
                printf("\nEnter the number which you want to find in the BST : \n");
                scanf("%d", &number);
                found = searchfor(treeroot1, number);
                if (found == NULL)
                {
                    printf("\nThe element couldn't be found in the tree!\n");
                }
                else
                {
                    printf("\nThe element %d has been found in the tree!\n", found->data);
                }
            }
            break;
        case 10:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                int number = countleaves(treeroot1);
                printf("\nThe tree has %d leaf nodes!\n", number);
            }
            break;
        case 11:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                printf("\nThe tree has %d non-leaf nodes\n", count(treeroot1) - countleaves(treeroot1));
            }
            break;
        case 12:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                treeroot2 = create();
                int whether = equal(treeroot1, treeroot2);
                if (whether == 1)
                {
                    printf("\nThe inputed two trees are equal!\n");
                }
                else
                {
                    printf("\nThe inputed two trees are not equal!\n");
                }
            }
            break;
        case 13:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                mirrortreeroot = copier(treeroot1);
                mirror(mirrortreeroot);
                printf("\nThe tree has been mirrored and the traversals of the mirrored tree are : \n");
                inorder(mirrortreeroot);
                printf("\n");
                preorder(mirrortreeroot);
                printf("\n");
                postorder(mirrortreeroot);
                printf("\n");
            }
            break;
        case 14:
            if (treeroot1 == NULL)
            {
                printf("\nThe tree is empty!\n");
            }
            else
            {
                lot(treeroot1);
            }
            break;
        case 15:
            mode = 0;
            break;
        default:
            printf("\nEnter a valid input ! \n");
            break;
        }
    }
}