#include <iostream>
#include "threestack.h"
using namespace std;

int main(int argc,char* argv[])
{
	threeStack<int> st;

	st.push(0,1);
	st.push(0,3);
	st.push(0,2);
	st.push(0,4);
	st.push(0,4);

	while(!st.empty(0))
	{
		cout<<st.top(0)<<endl;
		st.pop(0);
	}

	st.push(1,1);
	st.push(1,3);
	st.pop(1);
	st.push(1,2);
	st.push(1,4);
	st.push(1,4);

	while(!st.empty(1))
	{
		cout<<st.top(1)<<endl;
		st.pop(1);
	}
	st.push(2,1);
	st.pop(2);
	st.push(2,3);
	st.push(2,2);
	st.push(2,4);
	st.push(2,4);

	while(!st.empty(2))
	{
		cout<<st.top(2)<<endl;
		st.pop(2);
	}
	return 0;
}
