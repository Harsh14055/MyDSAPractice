#include <stdio.h>
#include <stdlib.h>

struct node
{
    /* data */
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (front == NULL)
        {
            /* code */
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        struct node *p = front;
        front = front->next;
        int val = p->data;
        free(p);
        printf("Removed : %d\n", val);
    }
}
void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }printf("\n");
}

int main()
{
    
    char n;
    while (n!='N'&&n!='n')
    {
        int i;
        printf("Enter\n1 for enqueuing\n2 for dequeuing\n3 for displaying\n4 to exit : ");
        scanf("%d",&i);
        switch (i) {
            case 1:
                int value;
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                n = 'n';
                return 0;
            default:
                printf("Enter a valid number\n");
        }
        printf("Enter any key to continue or 'n' or 'N' to stop : ");
        scanf(" %c",&n);
    }
    
    return 0;
}