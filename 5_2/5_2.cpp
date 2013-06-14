#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


string toBinary(const string decimal)
{
	float f = atof(decimal.c_str());
	int i = (int)f;
	f -= i;
	string left = "";
	string right = "";
	while(0 != i)
	{
		left.insert(0,1,i%2 + 48);
		i /= 2;
	}
	if(string::npos == decimal.find('.'))
	{
		return left;
	}
	right.push_back('.');
	while(f > 0.0)
	{
		i = (int)(f * 2);
		right.push_back(i+48);
		f *= 2;
		f -= i;
	}
	return left + right;
	

}

int main(int argc,char* argv[])
{
	string s;
	cout<<"Please enter a decimal:"<<endl;
	cin>>s;
	s = toBinary(s);
	cout<<"Binary:"<<s<<endl;
	return 0;
}
