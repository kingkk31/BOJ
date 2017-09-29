#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N,M;
	cin>>N>>M;

	vector<int> vt(N,0);
	
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		
		for(int j=a-1;j<=b-1;j++)
			vt[j] = c;
	}

	for(int i=0;i<vt.size();i++)
		cout<<vt[i]<< " ";

	return 0;
} 