#include <stdio.h>
#include <stdlib.h>
/* THis file has the functions "display2d" which is to print the 
elements of 2d array and "multiply" function is code to perform matrix multiplication */
void display2d(int n,int m,int arr[n][m]){
	int i;int j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void multiply(int n,int m,int p,int o,int arr1[n][m],int arr2[p][o]){
	if (m!=p)
	{
		printf("Multiplication Not possible");
		return;
	}
	
	int arr3[n][o];
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < o; j++) {
            arr3[i][j] = 0;
        }
    }
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < o; j++)
		{
			for (int k = 0; k < m; k++)
			{
				arr3[i][j] = arr3[i][j] + arr1[i][k]*arr2[k][j];
			}
			
		}
		
	}display2d(n,o,arr3);
}
int main()
{
	
	int arr1[3][2] = {{1,2},{3,4},{5,6}};
	int arr2[2][3] = {{1,3,5},{2,4,6}};
	printf("First matrix : \n");
	display2d(3,2,arr1);
	printf("Second matrix : \n");
	display2d(2,3,arr2);
	printf("Product of matrices is : \n");
	multiply(3,2,2,3,arr1,arr2);
	return 0;
}