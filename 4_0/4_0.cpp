#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc,char* argv[])
{
	BST<char,int> bst;

	bst.put('a',1);
	bst.put('b',3);
	bst.put('c',2);
	bst.put('d',4);
	bst.put('e',4);
	cout<<bst.size()<<endl;
	cout<<bst.get('b')<<endl;
	bst.remove('d');

	return 0;
}
