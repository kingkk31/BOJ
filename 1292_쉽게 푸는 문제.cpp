#include <iostream>
#include <vector>
using namespace std;

int main(void)
{	
	int a,b;
	cin>>a>>b;

	vector<int> vt;
	int total = 0;

	for(int i=1;i<=b;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(vt.size() >= b)
				continue;

			vt.push_back(i);				
		}
	}

	for(int i=a-1;i<vt.size();i++)
		total += vt[i];
			
	cout<<total<<endl;

    return 0;
}
