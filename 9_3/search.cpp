#include <iostream>
using namespace std;

int search(const int value,int array[],int end)
{
	int start = 0;
	int mid = 0;
	end--;
	do{
		mid = (start + end)/2;
		if(value == array[mid])
		{
			return mid;
		}
		if(array[start] <= array[mid])
		{
			if(array[start]<=value && value<=array[end])
			{
				end = mid-1;
			}else
			{
				start = mid+1;
			}
		}else
		{
			if(array[mid]<=value && value<=array[end])
			{
				start = mid+1;
			}else
			{
				end = mid-1;
			}
		}
	}while(start<end);
	return -1;
}

int main(int argc,char* argv[])
{
	int array[] = {4,5,1,2,3};
	int index = search(2,array,sizeof(array)/sizeof(int));
	cout<<"index:"<<index<<endl;
	return 0;
}

