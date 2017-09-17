#include <iostream>
using namespace std;

int main(void)
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		int h,w,b;
		cin>>h>>w>>b;
		
		if(b%h == 0)
		{
			cout<<h;
		}
		else
		{
			cout<<b%h;
		}

		cout.fill('0');
		cout.width(2);

		if(b%h == 0)
		{
			cout<<(b/h);
		}
		else
		{
			cout<<(b/h)+1;
		}
		cout<<endl;
	}

	return 0;
}