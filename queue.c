#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueue(struct queue *qe,int ele){
    if (qe->r==(qe->size-1))
    {
        printf("The queue is full\n");
    }
    else
    {
        qe->r = qe->r + 1;
        qe->arr[qe->r] = ele;
        printf("Inserted %d\n",ele);
    }
    
    
}
void dequeue(struct queue *qe){
    if (qe->f==qe->r)
    {
        printf("queue is empty\n");
    }
    else
    {
        int t = qe->arr[qe->f+1];
        qe->f = qe->f + 1;
        printf("Removed element %d\n",t);
    }
    
}
void display(struct queue * qe){
    for (int i = qe->f+1; i < qe->r; i++)
    {
        printf("%d ",qe->arr[i]);
    }
    
}


int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 6;
    q->f=-1;
    q->r=-1;
    q->arr = (int *)malloc(q->size*sizeof(int));
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    dequeue(q);
    display(q);
    return 0;
}