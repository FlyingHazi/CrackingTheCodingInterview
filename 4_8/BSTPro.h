#include <list>
#include "BST.h"
using namespace std;

template <class K,class V>
class BSTPro:public BST<K,V>
{
	private:
		typedef typename BST<K,V>::node node;
		void printPath(const list<const node*> &path,typename list<const node*>::const_reverse_iterator it) const
		{
			cout<<(*it)->key<<'\t';
			while(it!=path.rbegin())
			{
				it--;
				cout<<(*it)->key<<'\t';
			}
			cout<<endl;
		}
	       void	findSumPath(const node* const end,const int sum,list<const node*> path) const
	       {
		       if(NULL == end)
		       {
			       return;
		       }
		       int temp = sum;
		       path.push_back(end);
		       for(typename list<const node*>::const_reverse_iterator it=path.rbegin();it!=path.rend();it++)
		       {
			       temp -= (*it)->value;
			       if(0 == temp)
			       {
				       this->printPath(path,it);
			       }
		       }
		       findSumPath(end->leftChild,sum,path);
		       findSumPath(end->rightChild,sum,path);
	       }
	public:
	       void findSumPath(const int sum) const
	       {
		       list<const node*> ls;
		       findSumPath(this->root,sum,ls);
	       }

};
