#include "stack.h"
typedef unsigned int size_type;
template <class T>
class stackwithmin : public stack<T>
{
	private:
		stack<T> minStack;
	public:
		~stackwithmin()
		{
			while(!minStack.empty())
			{
				minStack.pop();
			}
		}
		void push(const T e)
		{
			if(minStack.empty() || minStack.top() >= e)
			{
				minStack.push(e);
			}
			stack<T>::push(e);
		}
		void pop()
		{
			if(minStack.top() == stack<T>::top())
			{
				minStack.pop();
			}
			stack<T>::pop();
		}
		T min()
		{
			return minStack.top();
		}
};
