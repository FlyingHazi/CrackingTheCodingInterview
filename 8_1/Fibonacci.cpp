#include <iostream>

using namespace std;

int fibonacci(const int n)
{
	if(1 > n)
	{
		return -1;
	}
	if(1 == n || 2 == n)
	{
		return 1;
	}	
	return fibonacci(n-2) + fibonacci(n-1);
}


int main(int argc,char* argv[])
{
	int n = 0;
	int re = 0;
	cout<<"Please input the n:"<<endl;
	cin>>n;
	re = fibonacci(n);
	cout<<"Fibonacci("<<n<<")="<<re<<endl;
	return 0;
}
