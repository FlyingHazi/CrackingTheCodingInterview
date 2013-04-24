#include <iostream>
using namespace std;

void move(int,char,char,char);

int main(int argc, char* argv[])
{
	int num		= 0;
	char rod1	= NULL;
	char rod2	= NULL;
	char rod3	= NULL;

	cout<<"Please enter the quantity of disks:";
	cin>>num;
	cout<<"Please enter the srcRod:";
	cin>>rod1;
	cout<<"Please enter the midRod:";
	cin>>rod2;
	cout<<"Please enter the distRod:";
	cin>>rod3;

	move(num, rod1, rod2, rod3);

	return 0;
}

void move(int num, char srcRod, char midRod, char distRod)
{
	if(1 == num)
	{
		cout<<srcRod<<" --> "<<distRod<<endl;
		return;
	}
	
	move(num-1,srcRod,distRod,midRod);
	cout<<srcRod<<" --> "<<distRod<<endl;
	move(num-1,midRod,srcRod,distRod);
}
