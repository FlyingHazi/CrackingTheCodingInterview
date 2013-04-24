#include <iostream>
#include <cstring>
#include <list>

using namespace std;

void printMatrix(int *p,int r,int c)
{
	for(int i=0;i!=r;i++)
	{
		for(int j=0;j!=c;j++)
		{
			cout<<*(p+c*i+j)<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}

void setMatrixZero(int *p,int r,int c)
{
	int *zr = new int[r];
	int *zc = new int[c];
	memset(zr,0,r*sizeof(int));
	memset(zc,0,c*sizeof(int));

	for(int i=0;i!=r;i++)
		for(int j=0;j!=c;j++)
		{
			if(0 == *(p + c*i + j))
			{
				zr[i] = 1;
				zc[j] = 1;
			}
		}

	for(int i=0;i!=r;i++)
		for(int j=0;j!=c;j++)
		{
			if(1 == zr[i] || 1 == zc[j])
			{
				*(p + c*i + j) = 0;
			}
		}
}

int main(int argc, char* argv[])
{
	int m1[][5] = {
		{1,1,0,1,0},
		{1,0,1,1,1},
		{1,1,1,1,1}
	};

	int m2[][6] = {
		{0,1,0,0,0,1},
		{1,1,1,1,1,1},
		{1,0,0,1,1,1},
		{1,1,1,1,1,1},
		{1,1,1,1,1,1}
	};

	int *p = NULL;

	p = &m1[0][0];
	printMatrix(p,3,5);
	setMatrixZero(p,3,5);
	printMatrix(p,3,5);

	p = &m2[0][0];
	printMatrix(p,5,6);
	setMatrixZero(p,5,6);
	printMatrix(p,5,6);

	return 0;
}
