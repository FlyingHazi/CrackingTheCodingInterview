#include <stdio.h>
using namespace std;

void printMatrix(int *matrix, int n);
void rotate(int *matrix,int n);
int main(int argc, char* argv[])
{
	int matrix1[][4] = {
		{1,1,2,2},
		{1,1,2,2},
		{3,3,4,4},
		{3,3,4,4}
	};
	int matrix2[][5] = {
		{1,1,2,3,3},
		{1,1,2,3,3},
		{4,4,5,6,6},
		{7,7,8,9,9},
		{7,7,8,9,9}
	};
	int n1 = 4;
	int n2 = 5;

	int *p = &matrix1[0][0];
	printMatrix(p,n1);
	rotate(p,n1);
	printMatrix(p,n1);

	p = &matrix2[0][0];
	printMatrix(p,n2);
	rotate(p,n2);
	printMatrix(p,n2);

	return 0;
}

void printMatrix(int *matrix, int n)
{
	for(int i=0;i!=n;i++)
	{
		for(int j=0;j!=n;j++)
		{
			printf("%d ",matrix[i*n+j]);
		}
		printf("\r\n");
	}
	printf("\r\n");
}

void rotate(int *matrix,int n)
{
	if(n<2)
	{
		return;
	}

	int t = 0;
	for(int layer=0;layer<n/2;layer++)
	{
		for(int i=layer;i!=n-layer-1;i++)
		{
			//temp
			t = matrix[layer*n+i];

			//right --> top
			matrix[layer*n+i] = matrix[i*n+n-1-layer];

			//bottom -- > right
			matrix[i*n+n-1-layer] = matrix[(n-1-layer)*n+n-1-i];

			//left --> bottom
			matrix[(n-1-layer)*n+n-1-i] = matrix[(n-1-i)*n+layer];

			//top --> left
			matrix[(n-1-i)*n+layer] = t;
		}

	}
}

