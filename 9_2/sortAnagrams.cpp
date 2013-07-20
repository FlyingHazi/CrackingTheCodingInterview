#include <iostream>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <vector>
using namespace std;


bool anagramsCompare(const string &a,const string &b)
{
	string sa = a;
	string sb = b;
       	sort(sa.begin(),sa.end());
	sort(sb.begin(),sb.end());
	return sa < sb;
}

void anagramsSort(vector<string> &vs)
{
	sort(vs.begin(),vs.end(),anagramsCompare);
}

int main(int argc,char* argv[])
{
	vector<string> vs = vector<string>{"aa","bb","aa","aa","cc","bb"};
	anagramsSort(vs);
	for(unsigned int i=0;i!=vs.size();i++)
	{
		cout<<vs[i]<<endl;
	}
	return 0;
}
