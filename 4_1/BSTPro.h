#include "BST.h"
#include <stack>
#include <algorithm>
using namespace std;

template <class K,class V>
class BSTPro:public BST<K,V>
{
	private:
		int minDepth(node* np)
		{
			if(NULL == np)
			{
				return 0;
			}
			return 1 + min(this->minDepth(this->leftChild),this->minDepth(this->rightChild));
		}
		int maxDepth(node* np)
		{
			if(NULL == np)
			{
				return 0;
			}
			return 1 + max(this->maxDepth(this->leftChild),this->maxDepth(this->rightChild));
		}
	public:
		bool isBalanced()
		{
			return this->maxDepth(this->root) - this->minDepth(this->root) > 1;
		}
};
