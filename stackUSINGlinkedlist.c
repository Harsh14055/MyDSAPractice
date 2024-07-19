#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node * push(struct node* head,int e){
	struct node * ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = e;
	ptr->next=head;
	
	return ptr;
}
void display(struct node* head){
	struct node *ptr;
	ptr = head;
	while (ptr!=NULL)
    {
    printf("%d ",ptr->data);
    ptr = ptr->next;
    }
}
struct node * pop(struct node* head){
	struct node* ptr = (struct node *)malloc(sizeof(struct node));
	if(head==NULL){
		free(ptr);
		printf("stack underflow");
	}
	else{
		ptr = head;
		head = ptr->next;
		free(ptr);
		return head;
	}
}

int main(){
	struct node * head = (struct node *)malloc(sizeof(struct node));
	int i;char n;
	head = NULL;
	while(n != 'n' && n!='N'){
	printf("Enter\n1 to push into stack\n2 to pop from stack\n3 to display the elements\n4 to exit : ");
	scanf("%d",&i);
	
	switch(i)
	{
	case 1:
		int e;
		printf("Enter the element you want to push : ");scanf("%d",&e);
		head = push(head,e);
		break;
	case 2:
		head = pop(head);display(head);
		break;
	case 3:
		display(head);printf("\n");
	case 4:
		n = 'n';
		break;
	default:
		printf("Enter a valid number");
		break;
	}printf("enter any key to continue or n or N to stop : ");scanf(" %c",&n);
	}
	return 0;
}
