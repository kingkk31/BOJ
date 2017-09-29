#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	set<int> hs;

	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		hs.insert(a);
	}

	set<int>::iterator itr = hs.begin();

	while(itr != hs.end())
	{
		cout<<*itr++<<endl;
	}

	return 0;
}