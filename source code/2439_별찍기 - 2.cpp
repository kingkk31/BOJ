#include <iostream>
using namespace std;

int main(void)
{	
    int T;
	cin>>T;

	for(int i=1;i<=T;i++)
	{
		for(int a=T;a>i;a--)
			cout<<" ";
		
		for(int j=0;j<i;j++)
			cout<<"*";
		cout<<endl;
	}

	return 0;
}