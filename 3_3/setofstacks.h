#include <list>
using namespace std;

template <class T>
class setofstacks
{
	private:
		list<list<T> *> stacks;
		typename list<list<T> *>::iterator cur;
		int capacity;
		int totalSize;
	public:
		setofstacks(int capacity=10)
		{
			this->capacity = capacity;
			this->totalSize = 0;
			stacks.push_back(new list<T>());
			cur = stacks.begin();
		}
		~setofstacks()
		{
			for(typename list<list<T> *>::iterator it=stacks.begin();it!=stacks.end();it++)
			{
				delete *it;
			}
		}
		void push(const T e)
		{
			if((*cur)->size() == this->capacity)
			{
				stacks.push_back(new list<T>());
				cur++;
			}
			(*cur)->push_back(e);
			++this->totalSize;
		}
		T pop()
		{
			if((*cur)->empty())
			{
				--cur;
				stacks.pop_back();
			}
			T temp = (*cur)->back();
			(*cur)->pop_back();
			--this->totalSize;
			return temp;
		}
		T popAt(int index)
		{
			typename list<list<T> *>::iterator it=this->stacks.begin(),bt,nt;
			for(int i=0;i!=index;i++)
			{
				++it;
			}
			T temp = (*it)->back();
			(*it)->pop_back();
			bt=it;
			bt++;
			nt = bt;
			while(bt!=stacks.end())
			{
				(*it)->push_back((*bt)->front());
				(*bt)->pop_front();
				if((*bt)->empty())
				{
					nt = bt;
					if(stacks.end() == ++nt)
					{
						stacks.pop_back();
						--cur;
						break;
					}
				}
				++it;
				++bt;
			}
			--this->totalSize;
			return temp;
		}
		int size()
		{
			return this->totalSize;
		}
		bool empty()
		{
			return 0==this->totalSize;
		}
};
