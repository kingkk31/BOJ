#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main(void)
{
	vector<vector<int> > map;
	
	for(int i=0;i<1001;i++)
	{
		vector<int> in;
		in.assign(1001,-1);
		map.push_back(in);
	}
	
	int N;
	cin>>N;

	vector<int> vt;
	vt.assign(N,0);
	
	for(int i=0;i<N;i++)
	{
		int y,x,height,length;
		cin>>y>>x>>height>>length;
		
		for(int a=y;a<y+height;a++)
		{
			for(int b=x;b<x+length;b++)
			{
				if(map[a][b] != -1)
					vt[map[a][b]]--;
				
				map[a][b] = i;
				vt[i]++;
			}
		}
	}
	
	for(int i=0;i<N;i++)
		cout<<vt[i]<<endl;

	return 0;
}
