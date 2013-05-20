#include <iostream>
#include "BSTPro.h"
using namespace std;

void addToTree(const char* array,const unsigned int size,BSTPro<char,int> &bst)
{
	const char* p = NULL;
	if(0 == size)
	{
		return;
	}
	p = array + size/2;
	bst.put(*p,1);
	addToTree(array,p-array,bst);
	addToTree(p+1,(array+size)-(p+1),bst);
}

int main(int argc,char* argv[])
{
	BSTPro<char,int> bst;

	char array[10] = {'a','b','c','d','e','f','g','h','i','j'};
	addToTree(array,sizeof(array),bst);
//	bst.put('a',1);
//	bst.put('b',1);
//	bst.put('c',1);
//	bst.put('d',1);
//	bst.put('e',1);
	cout<<bst.size()<<endl;
	bst.findCommomAncestor('b','e');
	return 0;
}
