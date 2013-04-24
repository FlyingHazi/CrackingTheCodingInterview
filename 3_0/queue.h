typedef unsigned int size_type;
template <class T>
class queue
{
	private:
		class node
		{
			public:
				node* prev;
				node* next;
				T data;
		};

		node* frontNode;
		node* backNode;
		size_type queueSize;
	public:
		queue()
		{
			this->frontNode=NULL;
			this->backNode=NULL;
			this->queueSize=0;
		}
		~queue()
		{
			while(this->frontNode)
			{
				node* tmp = this->frontNode;
				this->pop();
				delete tmp;
			}
		}
		void push(const T e)
		{
			node* pNode = new node();
			pNode->data = e;
			pNode->prev = this->backNode;
			pNode->next = NULL;
			if(NULL!=this->backNode)
			{
				this->backNode->next = pNode;
			}
			else
			{
				this->frontNode = pNode;
			}
			this->backNode = pNode;
			++this->queueSize;
		}
		void pop()
		{
			if(NULL==this->frontNode)
			{
				return;
			}
			node* pNode = this->frontNode;
			this->frontNode = pNode->next;
			if(NULL!=this->frontNode)
			{
				this->frontNode->prev = NULL;
			}
			else
			{
				this->backNode = NULL;
			}
			delete pNode;
			--this->queueSize;
		}
		T& front()
		{
			return this->frontNode->data;
		}
		T& back()
		{
			return this->backNode->data;
		}
		size_type size()
		{
			return this->queueSize;
		}
		bool empty()
		{
			return 0==this->queueSize;
		}
};
