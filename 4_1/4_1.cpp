#include <iostream>
#include "BSTPro.h"
using namespace std;

int main(int argc,char* argv[])
{
	BSTPro<char,int> bst;

	bst.put('a',1);
	bst.put('b',3);
	bst.put('c',2);
	bst.put('d',4);
	bst.put('e',4);
	cout<<bst.size()<<endl;
	if(bst.isBalanced())
	{
		cout<<"balanced"<<endl;
	}else
	{
		cout<<"not balanced"<<endl;
	}
	cout<<bst.get('b')<<endl;
	bst.remove('a');
	bst.remove('b');
	bst.remove('c');
	bst.remove('d');
	cout<<bst.get('f')<<endl;
	bst.remove('e');
	cout<<bst.size()<<endl;
	return 0;
}
