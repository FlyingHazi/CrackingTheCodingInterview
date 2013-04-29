#include <iostream>
#include "myqueue.h"
using namespace std;

int main(int argc,char* argv[])
{
	myqueue<int> st;

	st.push(1);
	st.push(3);
	st.push(2);
	st.push(0);
	st.push(4);
	cout<<endl;

	while(!st.empty())
	{
		cout<<st.pop()<<endl;
	}

	return 0;
}
