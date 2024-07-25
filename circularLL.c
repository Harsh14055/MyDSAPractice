#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void display(node *head)
{
    if (head->next == head)
    {
        printf("List is empty");
        return;
    }
    node *ptr = head->next;
    while (ptr->next != head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
}

node *insertatBegin(node *head, int val)
{
    node *p = (node *)malloc(sizeof(node));
    if (head->next == head)
    {
        p->data = val;
        p->next = head;
        head->next = p;
        return head;
    }
    else
    {
        p->data = val;
        p->next = head->next;
        head->next = p;
        return head;
    }
}
node *insertAtindex(node *head)
{
    node *ptr = head->next;
    int count = 1;
    int ind;
    int val;
    while (ptr->next != head)
    {
        ptr = ptr->next;
        count++;
    }
    printf("Number of elements in the list : %d\n", count);
    printf("Enter the index after which you want to insert : ");
    scanf("%d", &ind);
    if (ind < 0 || ind >= count)
    {
        printf("List Index out of range");
        return head;
    }
    else
    {
        printf("Enter the value you want to insert : ");
        scanf("%d", &val);
        node *p = (node *)malloc(sizeof(node));
        ptr = head->next;
        int k = 0;
        while (k < ind)
        {
            ptr = ptr->next;
            k++;
        }
        p->data = val;
        p->next = ptr->next;
        ptr->next = p;
        return head;
    }
}
node *insertAtend(node *head, int val)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = val;
    if (head->next == head)
    {
        head->next = p;
        p->next = head;
        return head;
    }
    else
    {
        node *ptr = head->next;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = p;
        p->next = head;
        return head;
    }
}
node *deletefirst(node *head)
{
    if (head->next == head)
    {
        printf("Empty list :(\n");
        return head;
    }
    node *ptr = head->next;
    head->next = ptr->next;
    free(ptr);
    return head;
}

node *deleteatindex(node *head)
{
    int ind;
    int count = 1;
    node *ptr = head->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
        count++;
    }
    printf("Number of elements in the list : %d\n", count);
    printf("Enter the index which you want to delete : ");
    scanf("%d", &ind);
    if (ind < 0 || ind >= count)
    {
        printf("List index out of range :(");
    }
    else
    {
        int k = 1;
        node *p = head;
        node *q = head->next;
        while (k <= ind)
        {
            p = p->next;
            q = q->next;
            k++;
        }
        p->next = q->next;
        free(q);
        return head;
    }
}

node *deletelast(node *head)
{

    if (head->next == head)
    {
        printf("Empty list :(\n");
        return head;
    }
    else
    {
        node *q = head;
        node *ptr = head->next;
        while (ptr->next != head)
        {
            q = q->next;
            ptr = ptr->next;
        }
        q->next = head;
        free(ptr);

        return head;
    }
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->next = head;
    int i;
    char n;
    while (n != 'n' && n != 'N')
    {
        printf("Enter\n1 to insert at beginning\n2 to insert at end\n3 to insert at index\n4 to delete first element\n5 to delete last element\n6 to delete element at index\n7 to display : ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            int val;
            int o;
            printf("How many values you want to insert : ");
            scanf("%d", &o);
            for (int j = 0; j < o; j++)
            {

                printf("Enter the value to insert : ");
                scanf("%d", &val);
                head = insertatBegin(head, val);
            }

            break;
        case 2:
            int v;
            int d;
            printf("How many values you want to insert : ");
            scanf("%d", &d);
            for (int j = 0; j < d; j++)
            {

                printf("Enter the value to insert : ");
                scanf("%d", &val);
                head = insertAtend(head, val);
            }
            break;
        case 3:
            head = insertAtindex(head);
            display(head);
            break;
        case 4:
            head = deletefirst(head);
            display(head);
            break;
        case 5:
            head = deletelast(head);
            display(head);
            break;
        case 6:
            head = deleteatindex(head);
            display(head);
            break;
        case 7:
            display(head);
            break;
        default:
            printf("Enter a valid number...");
            break;
        }
        printf("Enter n/N to exit or any other key to continue : ");
        scanf(" %c", &n);
    }

    return 0;
}