#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void compactq()
{
    int i;
    for (i = front + 1; i <= rear; i++)
    {
        queue[i - front - 1] = queue[i];
    }
    rear = (rear - front - 1);
    front = front - front - 1;
    //har ek element se hum front + 1 amount ghata rahe hain, even from rear and front itself, front  +1 index se leftwards shift kara hai har cheez ko and in the end, front ko bhi
}
void insertq(int value)
{
    int var = isfull();
    if (var == 1)
    {
        printf("\nQUEUE OVERFLOW ENCOUNTERED\n");
    }
    else
    {
        queue[rear++] = value;
    }
}
int isfull()
{
    if (rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
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
int deleteq()
{
    int var = isempty();
    if (var == 1)
    {
        printf("QUEUE UNDERFLOW ENCOUNTERED\n");
        return -9999;
    }
    else
    {
        return queue[++front];
    }
}
void display()
{
    int var = isempty();
    if (var == 1)
    {
        printf("QUEUE is empty\n");
    }
    else
    {
        printf("The current status of the queue is : \n");
        int i;
        for (i = front + 1; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
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
int main()
{
    int mode = 1;
    int var;
    int check;
    int input;
    printf("Welcome to the Queue!\n");
    while (mode)
    {
        printf("\nYou have the following options : \n1. Insert into queue\n2. Delete from Queue\n3. Display the Queue\n4. CompactQ\n5. Display the front\n6. Display the rear\n7. Exit\nEnter your choice : ");
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
        	compactq();
        	printf("Queue has been compacted!\n");
        	break;
        case 5:
            getfront();
            break;
        case 6:
            getrear();
            break;
        case 7:
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
