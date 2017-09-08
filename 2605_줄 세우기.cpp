#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vt;
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		vt.insert(vt.begin()+a,i);
	}

	for(int j=(n-1);j>=0;j--)
	{
		cout<<vt[j]<<" ";
	}

	return 0;
}