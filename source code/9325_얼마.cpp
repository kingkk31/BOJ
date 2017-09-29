#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int T;
	cin>>T;

	for(int i=0;i<T;i++)
	{
		int s,n, total=0;
		cin>>s;
		total += s;
		
		cin>>n;
		for(int j=0;j<n;j++)
		{
			int q,p;
			cin>>q>>p;
			total += q*p;
		}

		cout<<total<<endl;
	}

	return 0;
}
