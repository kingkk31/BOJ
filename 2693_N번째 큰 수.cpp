#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(void)
{
	int T;
	cin>>T;

	for(int i=0;i<T;i++)
	{
		set<int, greater<int> > st;
		for(int j=0;j<10;j++)
		{
			int num;
			cin>>num;
			st.insert(num);
		}
		set<int, greater<int> >::iterator itr = st.begin();

		itr++;
		itr++;

		cout<<*itr<<endl;
	}

	return 0;
}