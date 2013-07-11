#include <iostream>
#include <cstring>
using namespace std;

#define N 5

typedef struct _coordinate
{
	int x;
	int y;
}coordinate;

const bool matrix[N][N] = 
{
	{ true,false,true,true,true},
	{ true,true,true,true,true},
	{ true,true,true,true,true},
	{ true,true,true,true,true},
	{ true,true,true,true,true},
};

void findPrev(int stepc,coordinate (&stepv)[2*(N-1)])
{
	coordinate next = {0};
	memcpy(&next,&stepv[stepc],sizeof(coordinate));
	stepc++;
	if(0 < next.x)
	{
		stepv[stepc].x = next.x - 1;
		stepv[stepc].y = next.y;
		if(true == matrix[stepv[stepc].x][stepv[stepc].y])
		{
			findPrev(stepc,stepv);
		}
	}

	if(0 < next.y)
	{
		stepv[stepc].x = next.x;
		stepv[stepc].y = next.y -1;
		if(true == matrix[stepv[stepc].x][stepv[stepc].y])
		{
			findPrev(stepc,stepv);
		}
	}
	if(0!=next.x || 0!=next.y)
	{
		return;
	}
	for(int i=2*(N-1);i>=0;i--)
	{
		cout<<"{"<<stepv[i].x<<","<<stepv[i].y<<"}"<<"\t";
	}
	cout<<endl;
}

int main(int argc,char* argv[])
{
	coordinate steps[2*(N-1)] = {0};
	steps[0].x = N-1;
	steps[0].y = N-1;
	findPrev(0,steps);
	return 0;
}
