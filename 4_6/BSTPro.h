#include "BST.h"

template <class K,class V>
class BSTPro:public BST<K,V>
{
	private: 
		int commonAncestor(typename BST<K,V>::node* root,const typename BST<K,V>::node* na,const typename BST<K,V>::node* nb,typename BST<K,V>::node** ancestor) const
		{
			const unsigned int none_found = 0;
			const unsigned int one_found = 1;
			const unsigned int two_found = 2;
			unsigned int ret = none_found;
			if(NULL == root)
			{
				*ancestor = NULL;
				return none_found;
			}
			ret += commonAncestor(root->leftChild,na,nb,ancestor);
			if(NULL != *ancestor)
			{
				return two_found;
			}
			ret += commonAncestor(root->rightChild,na,nb,ancestor);
			if(NULL != *ancestor)
			{
				return two_found;
			}
			if(root->leftChild == na || root->leftChild == nb)
			{
				ret += one_found;
			}
			if(root->rightChild == na || root->rightChild == nb)
			{
				ret += one_found;
			}
			if(two_found == ret)
			{
				*ancestor = root;
			}
			return  ret;



		}
	public:
		void	findCommomAncestor(const K ka,const K kb) const
		{
			typename BST<K,V>::node *na=NULL,*nb=NULL,*np=this->root;
			while(NULL != np)
			{
				if(np->key == ka)
				{
					na = np;
					break;
				}else if(np->key > ka)
				{
					np = np->leftChild;
				}else
				{
					np = np->rightChild;
				}
			}
			np = this->root;
			while(NULL != np)
			{
				if(np->key == kb)
				{
					nb = np;
					break;
				}else if(np->key > kb)
				{
					np = np->leftChild;
				}else
				{
					np = np->rightChild;
				}
			}
			if(NULL == na || NULL == nb)
			{
				cout<<"node not found."<<endl;
				return;
			}
			commonAncestor(this->root,na,nb,&np);
			if(NULL != np)
			{
				cout<<"common ancestor "<<np->key<<endl;
			}else
			{
				cout<<"no common ancestor."<<endl;
			}
		}
};
