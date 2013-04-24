#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

int main(int argc,char* argv[])
{
	stack<int> st;

	st.push(1);
	st.push(3);
	st.push(2);
	st.push(4);
	st.push(4);

	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}

	queue<int> q;
	q.push(1);
	q.push(3);
	q.push(2);
	q.push(4);
	q.push(4);

	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
}
