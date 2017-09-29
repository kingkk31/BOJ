#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string str;
	cin>>str;

	vector<int> vt(26,0);

	for(int i=0;i<26;i++)
	{
		int a = 0;
		string::iterator itr = str.begin();
		while(itr != str.end())
		{
			if(*itr == 'a'+i)
				vt[i]++;
			
			itr++;
		}
	}

	for(int i=0;i<26;i++)
		cout<<vt[i]<<" ";

	return 0;
} 