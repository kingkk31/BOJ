#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
 
int main(void) 
{
	int n,m;
	cin>>n>>m;

	vector<int> vt;

	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		vt.push_back(num);
	}

	for(int i=0;i<vt.size();i++)
	{
		if(vt[i] < m)
			cout<<vt[i]<<" ";
	}

	return 0;
}
