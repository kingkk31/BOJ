#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string str;
	cin>>str;

	vector<int> vt(26,-1);

	for(int i=0;i<26;i++)
	{
		string::iterator itr = find(str.begin(),str.end(), 'a'+i);
		
		if(itr != str.end())
			vt[i] = itr - str.begin();
	}

	for(int i=0;i<26;i++)
		cout<<vt[i]<<" ";

	return 0;
} 