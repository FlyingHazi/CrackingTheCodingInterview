typedef unsigned int size_type;
template <class T>
class stack
{
	private:

		class node
		{
			public:
				node* prev;
				T data;
		};
		node* topNode;
		size_type stackSize;
	public:
		stack()
		{
			this->topNode=NULL;
			this->stackSize=0;
		}
		~stack()
		{
			while(this->topNode)
			{
				node* tmp = this->topNode;
				this->pop();
				delete tmp;
			}
		}
		void push(const T e)
		{
			node* pNode = new node();
			pNode->data = e;
			pNode->prev = this->topNode;
			this->topNode = pNode;
			++this->stackSize;
		}
		void pop()
		{
			if(NULL==this->topNode)
			{
				return;
			}
			node* pNode = this->topNode;
			this->topNode = pNode->prev;
			delete pNode;
			--this->stackSize;
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
