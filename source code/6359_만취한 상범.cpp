#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N;
	cin>>N;

	vector<bool> vt;
	
	for(int i=0;i<N;i++)
	{
		int n;
		cin>>n;

		vt.assign(n+1,1);

		for(int j=1;j<n+1;j++)
		{
			int a=1;
			while((a*j) < vt.size())
			{
				if(vt[a*j] == 0)
					vt[a*j] = 1;
				else
					vt[a*j] = 0;

				a++;
			}
		}

		int es=0;
		for(int j=1;j<n+1;j++)
			if(vt[j] == 0)
				es++;

		cout<<es<<endl;
			
	}

	return 0;
}