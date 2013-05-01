#include <stack>
template <class K,class V>
class BST
{
	private:
		class node
		{
			node* parent;
			node* leftChild;
			node* rightChild;
			K key;
			V value;
		};
		node* root;
		int tsize;
	public:
	BST()
	{
		root = NULL;
		tsize = 0;
	}
	~BST()
	{
		stack<node *> *st = new stack();
		if(NULL != root)
		{
			st->push(this->root);
		}
		while(!st->empty())
		{
			if(NULL != st->top()->leftChild)
			{
				st->push(st->top()->leftChild);
			}else if(NULL != st->top()->rightChild)
			{
				st->push(st->top()->rightChild);
			}else
			{
				node *p = st->top()->parent;
				if(NULL != p)
				{
					if(st->top() != p->rightChild)
					{
						p->leftChild = NULL;
					}else
					{
						p->rightChild = NULL;
					}
				}
				delete st->top();
				st->pop();
			}
		}
	}
	V get(K key)
	{
		node* p = this->root;
		while(NULL != p)
		{
			if(key == p->key)
			{
				return p->value;
			}else if(key < p->key)
			{
				p = p->leftChild;
			}else
			{
				p = p->rightChild;
			}
		}
	}
	void put(K key,V value)
	{
	}
	void delete(K key)
	{
	}
	int size()
	{
	}
};
