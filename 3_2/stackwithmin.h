#include "stack.h"
typedef unsigned int size_type;
template <class T>
class stackwithmin
{
	private:
		class node
		{
			public:
				node* prev;
				T data;
		};
		stack<node*> minstack;

		node* topNode;
		size_type stackSize;
	public:
		stackwithmin()
		{
			this->topNode=NULL;
			this->stackSize=0;
		}
		~stackwithmin()
		{
			while(this->topNode)
			{
				node* tmp = this->topNode;
				this->pop();
				delete tmp;
			}
			while(!minstack.empty())
			{
				minstack.pop();
			}
		}
		void push(const T e)
		{
			node* pNode = new node();
			pNode->data = e;
			pNode->prev = this->topNode;
			this->topNode = pNode;
			++this->stackSize;
			if(this->minstack.empty() || minstack.top()->data > pNode->data)
			{
				minstack.push(pNode);
			}
		}
		void pop()
		{
			if(NULL==this->topNode)
			{
				return;
			}
			node* pNode = this->topNode;
			this->topNode = pNode->prev;
			if(!minstack.empty() && minstack.top() == pNode)
			{
				minstack.pop();
			}
			delete pNode;
			--this->stackSize;
		}
		T min()
		{
			return this->minstack.top()->data;
		}
		T& top()
		{
			return this->topNode->data;
		}
		size_type size()
		{
			return this->stackSize;
		}
		bool empty()
		{
			return 0==this->stackSize;
		}
};
