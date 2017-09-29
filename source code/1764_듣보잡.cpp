#include <iostream>
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
	vector<string> vt;
	vector<string> check;

	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		vt.push_back(str);
	}

	sort(vt.begin(),vt.end());

	for(int i=0;i<m;i++)
	{
		string str;
		cin>>str;

		if(binary_search(vt.begin(),vt.end(), str))
			check.push_back(str);
	}

	cout<<check.size()<<endl;
	
	sort(check.begin(), check.end());

	for(int i=0;i<check.size();i++)
		cout<<check[i]<<endl;

	return 0;
}
