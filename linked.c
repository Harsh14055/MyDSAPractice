#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*next;
};

void linkedTraversal(struct node* ptr){
    while (ptr!=NULL)
    {
    printf("%d ",ptr->data);
    ptr = ptr->next;
    }
    }
struct node * inseratfirst(struct node * head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node * insertAtIndex(struct node* head,int data,int index){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;
    while (i!=index-1)
    {
        /* code */
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node * insertAtend(struct node * head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0 ;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    ptr->data = data;
    p->next = ptr;
    return head;
}

struct node * insertafterAnode(struct node *head,struct node * prevNode,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

struct node * deletefristNode(struct node * head){
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct node * deleteatindex(struct node * head,int index){
    int i=0;
    struct node * p = head;
    struct node * q = head->next;
    while (i<index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
    
}

struct node * deletefromEnd(struct node * head){
    struct node * p = head;
    struct node * q = p->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
    
}

int main()
{
    // Memory allocated in heap (dynamic)
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));
    head->data = 7;
    head->next = second;

    second->data=11;
    second->next=third;

    third->data=13;
    third->next=NULL;
    printf("Original linked list\n");
    linkedTraversal(head);
    printf("\n");
    printf("Inserting 23 at the beginning\n");
    head = inseratfirst(head,23);
    linkedTraversal(head);
    printf("\n");
    printf("Inserting 123 at index 2\n");
    head = insertAtIndex(head,123,2);
    linkedTraversal(head);
    printf("\n");
    printf("Inserting 999 at the end\n");
    head = insertAtend(head,999);
    linkedTraversal(head);
    printf("\n");
    printf("Inserting 89 after the second node\n");
    head = insertafterAnode(head,second,89);
    linkedTraversal(head);
    printf("\n");
    printf("Deleting the first node\n");
    head = deletefristNode(head);
    linkedTraversal(head);
    printf("\n");
    printf("Deleting node at index 3\n");
    head = deleteatindex(head,3);
    linkedTraversal(head);
    printf("\n");
    printf("Deleting the last node\n");
    head = deletefromEnd(head);
    linkedTraversal(head);
    printf("\n");
    return 0;
}