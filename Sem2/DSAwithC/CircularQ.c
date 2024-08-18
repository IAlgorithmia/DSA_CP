#include <stdio.h>
#define MAX 5
int front = 0;
int rear = 0;
int queue[MAX];
int isempty()
{
    if (front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getfront()
{
    int var = isempty();
    if (var == 1)
    {
        printf("The queue is empty!");
        return -9999;
    }
    else
    {
        return queue[front + 1];
    }
}
int getrear()
{
    int var = isempty();
    if (var == 1)
    {
        printf("The queue is empty!");
        return -9999;
    }
    else
    {
        return queue[rear];
    }
}
int isfull()
{
    // Condition for empty and full is coming out to be the same, hence we differentiate by defining the queue as full when only one space is left which will never be filled and shall remain empty always, front pe humesha koi element nahi rahega
    if ((rear + 1) % (MAX) == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insertq(int val)
{
    int var = isfull();
    if (var == 1)
    {
        printf("QUEUE OVERFLOW ENCOUNTERED\n");
    }         
    else
    {   
    rear = (rear + 1) % MAX;
    //Notice that rear se pehle vala space khali chutta hai because startiong from 0, rear becomes 1 after insertion
    queue[rear] = val;
    }

}
int deleteq()
{
    int var = isempty();
    if (var == 1)
    {
        printf("Queue UNDERFLOW ENCOUNTERED\n");
        return -9999;
    }
    else
    {
        front = (front + 1) % MAX;
        //front jahan pe hai vo jaga khali maani jayegi na
        return queue[front];
    }
}
void display()
{
    int var = isempty();
    if (var == 1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        int i = front + 1;
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ", queue[rear]); //Because upar dalne ke karand infinite loop ban jayega
    }
}
int main()
{
    int mode = 1;
    int var;
    int check;
    int input;
    printf("Welcome to the Queue!\n");
    while (mode)
    {
        printf("\nYou have the following options : \n1. Insert into queue\n2. Delete from Queue\n3. Display the Queue\n4. Exit\nEnter your choice : ");
        scanf("%d", &input);
        check = isfull();
        switch (input)
        {
        case 1:
            if (check == 1)
            {
                printf("QUEUE OVERFLOW ENCOUNTERED");
            }
            else
            {
                printf("Enter the value to be inserted : ");
                scanf("%d", &var);
                insertq(var);
                printf("%d has been inserted into the queue!\n", var);
            }
            break;
        case 2:
            var = deleteq();
            if (var != -9999)
            {
                printf("%d has been deleted from the queue!", var);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            getfront();
            break;
        case 5:
            getrear();
            break;
        case 6:
            printf("Nice having you, hope to see you soon!\n");
            mode = 0;
            break;
        default:
            printf("Please enter a valid input!\n");
            break;
        }
    }
    return 0;
}
