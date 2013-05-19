#include "BST.h"
#include <stack>
#include <algorithm>
using namespace std;

template <class K,class V>
class BSTPro:public BST<K,V>
{
	private:
		int minDepth(typename BST<K,V>::node* np)
		{
			if(NULL == np)
			{
				return 0;
			}
			return 1 + min(this->minDepth(np->leftChild),this->minDepth(np->rightChild));
		}
		int maxDepth(typename BST<K,V>::node* np)
		{
			if(NULL == np)
			{
				return 0;
			}
			return 1 + max(this->maxDepth(np->leftChild),this->maxDepth(np->rightChild));
		}
	public:
		bool isBalanced()
		{
			return this->maxDepth(this->root) - this->minDepth(this->root) < 2;
		}
};
