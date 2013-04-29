#include <iostream>
#include "setofstacks.h"
using namespace std;

int main(int argc,char* argv[])
{
	setofstacks<int> st(3);

	st.push(1);
	st.push(3);
	st.push(2);
	st.push(0);
	st.push(5);
	st.push(4);
	st.push(4);

	cout<<st.popAt(0)<<endl;
	cout<<st.popAt(0)<<endl;
	cout<<st.popAt(0)<<endl;
	cout<<st.popAt(0)<<endl;
	while(!st.empty())
	{
		cout<<st.pop()<<endl;
	}

	return 0;
}
