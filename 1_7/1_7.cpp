#include <iostream>
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
	list<int> rList,cList;
	for(int i=0;i!=r;i++)
		for(int j=0;j!=c;j++)
		{
			if(0 == *(p+c*i+j))
			{
				rList.push_back(i);
				break;
			}
		}

	for(int i=0;i!=c;i++)
		for(int j=0;j!=r;j++)
		{
			if(0 == *(p+c*j+i))
			{
				cList.push_back(i);
				break;
			}
		}

	for(list<int>::iterator it = rList.begin();it!=rList.end();it++)
	{
		for(int i=0;i!=c;i++)
		{
			*(p+*it*c+i) = 0;
		}
	}

	for(list<int>::iterator it = cList.begin();it!=cList.end();it++)
	{
		for(int i=0;i!=r;i++)
		{
			*(p+c*i+*it) = 0;
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
