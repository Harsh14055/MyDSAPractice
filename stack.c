#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int* arr;
};
int isEmpty(struct stack *ptr){
    if (ptr->top==-1)
    {
        printf("Stack is empty\n");
        return 1;
    }
    else
    {
        printf("Stack is not empty\n");
        return 0;
    }
}
int isFull(struct stack *ptr){
    if (ptr->top==ptr->size - 1)
    {
        /* code */
        printf("Stack is full\n");
        return 1;
    }
    else
    {
        printf("Not empty\n");
        return 0;
    }
}
void push(struct stack *ptr,int e){
    if (ptr->top != ptr->size - 1)
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = e;
    }
    else
    {
        printf("cannot push\n");
    }
    
    
}
void pop(struct stack *ptr){
    if (ptr->top != -1)
    {
        ptr->top = ptr->top - 1;
    }else{printf("Stack is empty");}
    
}
void display(struct stack *ptr){
    for (int i = 0; i < ptr->top+1; i++)
    {
        printf("%d ",ptr->arr[i]);
    }
    
}
void peek(struct stack *ptr){
    if (ptr->top >-1)
    {
        /* code */printf("%d\n",ptr->arr[ptr->top]);
    }
    
}
int main()
{
    
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    
    s -> size = 5;
    s -> top = -1;
    s -> arr = (int *)malloc(s->size * sizeof(int));
    printf("%d\n",isEmpty(s));
    push(s,5);
    isEmpty(s);
    push(s,10);
    push(s,15);
    push(s,20);
    push(s,25);
    push(s,100); //cannot push
    pop(s);
    pop(s);
    peek(s);
    pop(s);
    pop(s);
    pop(s); // stack emptied
    pop(s);
    display(s);printf("\n");
    isEmpty(s);
    
    
    
    
    return 0;
}