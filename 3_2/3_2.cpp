#include <iostream>
#include "stackwithmin.h"
using namespace std;

int main(int argc,char* argv[])
{
	stackwithmin<int> st;

	st.push(1);
	st.push(3);
	cout<<st.min()<<endl;
	st.push(2);
	st.push(0);
	cout<<st.min()<<endl;
	st.push(4);
	cout<<endl;

	while(!st.empty())
	{
		cout<<st.top()<<" : "<<st.min()<<endl;
		st.pop();
	}

	return 0;
}
