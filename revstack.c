#include <stdio.h>
#include <stdlib.h>
/*
This is code for string reversal using stacck

*/
struct stack{
    int size;
    int top;
    char *arr;
};

int pop(struct stack* ptr){
    if (ptr->top != -1)
    {
        /* code */
    
    int t;
    t = ptr->top;
    ptr->top = ptr->top - 1;
    return ptr->arr[t];
    }else{
        return 0;
    }
}
void push(struct stack* ptr,char e){
    if (ptr->top!=ptr->size-1)
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = e;
    }
    
}
void display(struct stack *ptr){
    for (int i = 0; i < ptr->top+1; i++)
    {
        printf("%c",ptr->arr[i]);
    }
    
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    struct stack * rev = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter size of the word : ");
    scanf("%d",&s->size);
    s->arr = (char *)malloc(s->size*(sizeof(char)));
    rev->size = s->size;
    rev->arr = (char *)malloc(rev->size*(sizeof(char)));
    rev->top = -1;
    s->top = -1;
    printf("Enter the word : ");
    for (int i = 0; i < s->size+1; i++)
    {
        scanf("%c",&s->arr[i]);
        s->top = s->top + 1;
    }
    for (int i = 0; i < rev->size; i++)
    {
        push(rev,pop(s));
    }
    display(rev);
    
    
    return 0;
}