#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    int N;
	cin>>N;
	
	multimap<int,string> vt;

	for(int i=0;i<N;i++)
	{
		int age;
		string name;
		cin>>age>>name;
		
		vt.insert(make_pair<int,string>(age,name));		
	}
		
	multimap<int,string>::iterator itr = vt.begin();

	for(int i=0;i<vt.size();i++)
	{
		cout<<itr->first<<" "<<itr->second<<endl;
		itr++;
	}

    return 0;
}
