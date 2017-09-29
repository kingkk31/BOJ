#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	int T;
	cin>>T;

	multiset<int> ms;

	int N;
	cin>>N;
	ms.insert(N);
	multiset<int>::iterator itr = ms.begin();
	cout<<*itr<<endl;

	for(int i=1;i<T;i++)
    {
		int N;
		cin>>N;

		ms.insert(N);
		if(ms.size() % 2 == 0)
        {
			if(*itr > N)
				--itr;
        }
		else
        {
			if(*itr <= N)
				++itr;
        }
		cout<<*itr<<endl;
    }

	return 0;
}