#include <iostream>
#include <stack>
using namespace std;

template <class T>
void sortstack(stack<T>& s1)
{
	stack<T> s2;
	int n = s1.size()/2;
	T temp;

	for(int i=0;i!=n;i++)
	{
		s2.push(s1.top());
		s1.pop();
		while(s1.size() > i)
		{
			if(s1.top()>=s2.top())
			{
				s2.push(s1.top());
				s1.pop();	
			}else
			{
				temp = s2.top();
				s2.pop();
				s2.push(s1.top());
				s2.push(temp);
				s1.pop();
			}
		}
		s1.push(s2.top());
		s2.pop();
		while(s2.size() > i)
		{
			if(s1.top()>=s2.top())
			{
				s1.push(s2.top());
				s2.pop();
			}else
			{
				temp = s1.top();
				s1.pop();
				s1.push(s2.top());
				s1.push(temp);
				s2.pop();
			}
		}
	}
	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
}

int main(int argc,char* argv[])
{
	stack<int> st;
	st.push(0);
	st.push(5);
	st.push(0);
	st.push(1);
	st.push(2);
	st.push(4);
	st.push(8);
	st.push(4);
	st.push(9);
	st.push(8);

	sortstack(st);
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
	return 0;
}
