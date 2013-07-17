#include <iostream>
#include <cmath>
using namespace std;

#define ROWS 8

const bool placeQueue(unsigned int (&rows)[ROWS],unsigned int row)
{
	if(ROWS == row)
	{
		return true;
	}
	bool b = true;
	for(unsigned int i=0;i!=ROWS;i++)
	{
		rows[row] = i;
		b = true;
		for(unsigned int j=0;j!=row;j++)
		{
			if(rows[j]==i || row-j==abs((int)i-(int)rows[j]))
			{
				b = false;
				break;
			}
		}
		if(b&&placeQueue(rows,row+1))
		{
			return true;
		}
	}
	return false;

}

int main(int argc,char* argv[])
{
	unsigned int rows[ROWS] = {0};
	if(false == placeQueue(rows,0))
	{
		cout<<"impossible"<<endl;
		return 0;
	}

	for(unsigned int i=0;i!=ROWS;i++)
	{
		for(unsigned int j=0;j!=ROWS;j++)
		{
			cout<<(rows[i]==j?1:0)<<",";
		}
		cout<<endl;
	}
	return 0;
}
