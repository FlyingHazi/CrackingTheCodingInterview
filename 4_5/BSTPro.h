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
			if(NULL == p->parent)
			{
				return NULL;
			}
			if(p == p->parent->leftChild)
			{
				return p->parent;
			}else
			{
				return successor(p->parent->parent);
			}
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
