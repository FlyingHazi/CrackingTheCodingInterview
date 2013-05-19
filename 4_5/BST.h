#include <string.h>
#include <list>
#include <stack>
#include <iostream>
using namespace std;
template <class K,class V>
class BST
{
	protected:
		class node
		{
			public:
				node(K key,V value)
				{
					this->key = key;
					this->value = value;
					this->parent = NULL;
					this->leftChild = NULL;
					this->rightChild = NULL;
				}
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
			stack<node *> *st = new stack<node *>();
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
			V value;
			memset(&value,0,sizeof(V));
			this->put(key,value);
			return value;
		}
		void put(K key,V value)
		{
			node* pn = new node(key,value);
			if(NULL == root)
			{
				root = pn;
				tsize = 1;
				return;
			}

			node** ppn = &root;
			while(true)
			{
				if(key == (*ppn)->key)
				{
					(*ppn)->value = value;
					break;
				}else if(key < (*ppn)->key)
				{
					if(NULL == (*ppn)->leftChild)
					{
						pn->parent = *ppn;
						(*ppn)->leftChild = pn;
						break;
					}
					ppn = &((*ppn)->leftChild);
				}else
				{
					if(NULL == (*ppn)->rightChild)
					{
						pn->parent = *ppn;
						(*ppn)->rightChild = pn;
						break;
					}
					ppn = &((*ppn)->rightChild);
				}
			}
			++tsize;
		}
		void remove(K key)
		{
			node* dn = root;
			node* cur = NULL;
			node** curp = NULL;
			while(NULL != dn)
			{
				if(dn->key == key)
				{
					break;
				}else if(key < dn->key)
				{
					dn = dn->leftChild;
				}else
				{
					dn = dn->rightChild;
				}
			}
			if(NULL == dn)
			{
				return;
			}
			if(NULL == dn->leftChild || NULL == dn->rightChild)
			{

				if(root == dn)
				{
					curp = &root;
				}else
				{
					curp = NULL==dn->parent->leftChild?(&dn->parent->rightChild):(&dn->parent->leftChild);
				}
				*curp = NULL==dn->leftChild?dn->rightChild:dn->leftChild;
				if(NULL != *curp)
				{
					(*curp)->parent = dn->parent;
				}
				delete dn;
			}else
			{
				cur = dn->leftChild;
				while(NULL != cur->rightChild)
				{
					cur = cur->rightChild;
				}
				if(cur == dn->leftChild)
				{
					dn->leftChild = NULL;
				}else
				{
					cur->parent->rightChild = NULL;
				}
				dn->key = cur->key;
				dn->value = cur->value;
				delete cur;
			}
			--tsize;
		}

		int size()
		{
			return tsize;
		}
};
