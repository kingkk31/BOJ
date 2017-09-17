#include <iostream>
#include <vector>
#include <list>
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

		list<int> temp;

		for(int j=a-1;j<=b-1;j++)
			temp.push_back(vt[j]);
				
		temp.reverse();
		
		for(int j=a-1;j<=b-1;j++)
		{
			vt[j] = temp.front();
			temp.pop_front();
		}
	}

	for(int i=0;i<vt.size();i++)
		cout<<vt[i]<<" ";

	return 0;
} 