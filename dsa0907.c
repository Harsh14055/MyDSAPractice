#include <stdio.h>

void insertion(int arr[]){
    int size ;int index;int element;
    printf("Enter size of array : ");
    scanf("%d",&size);
    printf("Enter the index where you want to insert : ");
    scanf("%d",&index);
    printf("Enter the element which you want to insert : ");
    scanf("%d",&element);
    int t;
    for (int i = size+1; i >= index; i--){
        t = arr[index];
        if(i==index){
            arr[i] = element;
            arr[i+1] = t;
        }
        else
        {
            arr[i+1] = arr[i];
        }
        
    }
    
}
void deletion(int arr[]){
    int size ;int index;
    printf("Enter size of array : ");
    scanf("%d",&size);
    printf("Enter the index from where you want to delete : ");
    scanf("%d",&index);
    
    for (int i = 0; i < size+1; i++)
    {
        if (i>=index)
        {
            arr[i] = arr[i+1];
        }
        
    }
    printf("\n");
    
}
void display(int arr[]){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    
    for (int i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
}
int main()
{
    int arr[100];
    int n;int x;
    while (n != 0)
    {
        printf("Enter 1 for insertion\n2 for deletion\n3 for display : ");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            insertion(arr);
            break;
        case 2:
            deletion(arr);
            break;
        case 3:
            display(arr);
            break;
        default:
            printf("Enter a valid number 1 or 2 or 3");
            break;
        }
        printf("\nEnter 0 to exit or any other key to continue : ");
        scanf("%d",&n);
    }
    
    return 0;
}