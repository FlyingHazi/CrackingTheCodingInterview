#include "BST.h"

template <class K,class V>
class BSTPro:public BST<K,V>
{
	private:
		typename BST<K,V>::node* successor(typename BST<K,V>::node* p)
		{
			typename BST<K,V>::node *q = NULL;
			if(NULL != p->rightChild)
			{
				q = p->rightChild;
				while(NULL != q->leftChild)
				{
					q = q->leftChild;
				}
				return q;
			}


			while(NULL != p->parent)
			{
				if(p == p->parent->leftChild)
				{
					return p->parent;
				}else
				{
					p = p->parent;
				}
			}
			return NULL;
		}
	public:
		void findSuccessor(K key)
		{
			typename BST<K,V>::node* p = this->root;
			while(NULL != p)
			{
				if(key == p->key)
				{
					break;
				}else if(key < p->key)
				{
					p = p->leftChild;
				}else
				{
					p = p->rightChild;
				}
			}
			if(NULL == p)
			{
				return;
			}
			typename BST<K,V>::node *q = successor(p);
			cout<<q->key<<endl;
		}
};
