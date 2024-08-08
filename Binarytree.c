#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node *createNode(int data)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
}
struct node *insertOnLeft(struct node *root, int data)
{
	root->left = createNode(data);
	return root;
}
struct node *insertOnRight(struct node *root, int data)
{
	root->right = createNode(data);
	return root;
}
void preOrder(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(struct node *root)
{
	//	L R root
	if (root == NULL)
	{
		return;
	}
	else
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}
void inOrder(struct node *root)
{
	//	L root R
	if (root == NULL)
	{
		return;
	}
	else
	{
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
int main()
{
	int i;
	char n;
    
	struct node* root = NULL;
	
	while (n!='n' && n!='N')
	{
	printf("Enter\n0 to insert element\n1 for inOrder traversal\n2 for preOrder traversal\n3 for postOrder traversal : ");
	scanf("%d", &i);
	
	switch (i)
	{
	case 0:
        int e;
        int d;
        printf("Enter the number of elements to insert : ");
        scanf("%d",&d);
        for (int i = 0; i < d; i++)
        {
        printf("Enter the element to insert : ");
        scanf("%d",&e);
        root = insert(root,e);
        }
        break;
	case 1:
		inOrder(root);
		printf("\n");
		break;
	case 2:
		preOrder(root);
		printf("\n");
		break;
	case 3:
		postOrder(root);
		printf("\n");
		break;
	default:
		break;
	}
	printf("Enter any key to continue and n/N to stop : ");
	scanf(" %c",&n);
	}
	return 0;
}
