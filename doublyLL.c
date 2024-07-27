#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void displayrev(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

struct node *insertAtBegin(struct node *head, int val)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->prev = NULL;
    p->next = head;
    if (head != NULL)
    {
        head->prev = p;
    }

    return p;
}

struct node *insertAtEnd(struct node *head, int val)
{
    struct node *ptr = head;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        p->prev = NULL;
        return p;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    p->data = val;
    p->next = NULL;
    ptr->next = p;
    p->prev = ptr;
    return head;
}

struct node *insertAtIndex(struct node *head, int val, int ind)
{
    struct node *ptr = head->next;
    int i = 0;int s = 0;
    struct node *r = head;
    while (r != NULL)
    {
        s = s + 1;
        r = r->next;
    }
    if (ind>=s)  
    {
        printf("List index Out of range :(");
    }
    while (i != ind-1)
    {
        ptr = ptr->next;
        i++;
    }
    
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->next = ptr->next;
    ptr->next = p;
    p->prev = ptr;
    return head;
}
struct node *deleteFirst(struct node *head)
{
    if (head==NULL)
    {
        printf("List empty :(");
        return head;
    }
    
    struct node *ptr = head;
    struct node *q = ptr->next;
    // head->next = ptr->next;
    // q->prev = head->next;
    free(ptr);
    return q;
}
struct node *deleteLast(struct node *head)
{
    if (head==NULL)
    {
        printf("List empty :(");
        return head;
    }
    struct node *ptr = head;
    struct node *q = ptr->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}
struct node *deleteAtindex(struct node *head, int ind)
{
    if (head==NULL)
    {
        printf("List empty :(");
        return head;
    }
    struct node *ptr = head;
    struct node *q = ptr->next;
    int i = 0;int s = 0;
    struct node *p = head;
    while (p != NULL)
    {
        s = s + 1;
        p = p->next;
    }
    if (ind>=s)  
    {
        printf("List index Out of range :(");
        return head;
    }
    while (i != ind - 1)
    {
        q = q->next;
        ptr = ptr->next;
        i++;
    }

    ptr->next = q->next;
    (q->next)->prev = ptr;
    free(q);
    return head;
}
int main()
{
    struct node *head = NULL;
    char n;
    while (n != 'N' && n != 'n')
    {
        printf("Enter\n");
        printf("1 to Insert at beginning\n");
        printf("2 to Insert at end\n");
        printf("3 to Insert at index\n");
        printf("4 to Delete first\n");
        printf("5 to Delete last\n");
        printf("6 to Delete at index\n");
        printf("7 to Display forward\n");
        printf("8 to Display reverse\n");
        printf("9 to Exit\n");

        int i;
        printf("Enter your choice: ");
        scanf("%d", &i);

        int val, ind;
        int t, e;
        switch (i)
        {
        case 1:
            printf("How many values do you want to add : ");
            scanf(" %d", &t);
            for (int j = 0; j < t; j++)
            {
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val);
                head = insertAtBegin(head, val);
            }
            display(head);
            break;
        case 2:
            printf("How many values do you want to add : ");
            scanf(" %d", &e);
            for (int j = 0; j < e; j++)
            {
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                head = insertAtEnd(head, val);
            }display(head);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter index: ");
            scanf("%d", &ind);
            head = insertAtIndex(head, val, ind);
            display(head);
            break;
        case 4:
            head = deleteFirst(head);
            display(head);
            break;
        case 5:
            head = deleteLast(head);
            display(head);
            break;
        case 6:
            printf("Enter index to delete: ");
            scanf("%d", &ind);
            head = deleteAtindex(head, ind);
            display(head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            displayrev(head);
            break;
        case 9:
            return 0;
        default:
            printf("Invalid choice\n");
        }

        // Check for exit condition
        printf("Enter n/N to exit or any other key to continue : ");
        scanf(" %c", &n);
    }
        return 0;
}