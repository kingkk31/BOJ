#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		vector<int> v;
		string str;
		cin>>str;
		for(int i=0;i<str.length();i++)
		{
			v.insert(v.begin()+i,str[i]);
		}

		for(int i=0;i<(str.length()/2)-1;i++)
		{
			v.erase(v.begin());
			v.erase(v.end()-1);
		}

		if(v[0]==v[1])
		{
			cout<<"Do-it"<<endl;
		}
		else
		{
			cout<<"Do-it-Not"<<endl;
		}
	}	
	return 0;
}