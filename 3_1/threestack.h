#include <cstring>
#define STACK_SIZE 256

template <class T>
class threeStack{
	private:
		class stackNode
		{
			public:
				T data;
				stackNode* prev;
		};

		stackNode stackarray[STACK_SIZE];
		stackNode* stacks[4];
		int usedIndex;

	public:
		threeStack()
		{

			stackarray[STACK_SIZE];
			memset(stacks,(int)NULL,sizeof(stacks));
			usedIndex = 0;
		}

		bool push(int index,T value)
		{
			stackNode* cur;
			if(index < 0 || index > 2)
			{
				return false;
			}
			if(NULL != stacks[3])
			{
				cur = stacks[3];
				stacks[3] = stacks[3]->prev;
			}
			else if(usedIndex != STACK_SIZE)
			{
				cur = &stackarray[usedIndex++];
			}
			else
			{
				return false;
			}
			cur->prev = stacks[index];
			cur->data = value;
			stacks[index] = cur;
			return true;
		}

		bool pop(int index)
		{
			stackNode* cur = NULL;
			if(index <0 || index > 2)
			{
				return false;
			}
			if(NULL == stacks[index])
			{
				return false;
			}
			cur = stacks[index];
			stacks[index] = cur->prev;
			cur->prev = stacks[3];
			stacks[3] = cur;
			return true;
		}

		T& top(int index)
		{
			return stacks[index]->data;
		}

		bool empty(int index)
		{
			return NULL==stacks[index];
		}
};
