#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(void)
{
    int N,M;
	cin>>N>>M;

	vector<int> vt;
	
	for(int i=0;i<N;i++)
		vt.push_back(i+1);

	for(int i=0;i<M;i++)
	{
		int a,b;
		cin>>a>>b;
		swap(vt[a-1],vt[b-1]);
	}

	for(int i=0;i<vt.size();i++)
		cout<<vt[i]<<" ";
 
    return 0;
}
