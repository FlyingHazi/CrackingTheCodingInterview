#include <stack>
using namespace std;

template <class T>
class myqueue
{
	private:
		stack<T> s1;
		stack<T> s2;
	public:
		void push(T e)
		{
			s1.push(e);
		}

		T pop()
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			T temp = s2.top();
			s2.pop();
			return temp;
		}
		int size()
		{
			return s1.size()+s2.size();
		}
		bool empty()
		{
			return s1.empty() && s2.empty();
		}
};
