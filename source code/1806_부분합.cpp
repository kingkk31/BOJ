#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	int N,S;
	cin>>N>>S;

	queue<int> qu;

	int mini = 100000;

	int total=0;

	for(int i=0;i<N;i++)
	{
		int num;
		cin>>num;
		qu.push(num);
		
		total += num;

		while(total >= S)
		{
			int n = qu.size();
			mini = min(mini,n);
			total -= qu.front();
			qu.pop();
		}
	}

	if(mini == 100000)
		mini = 0;

	cout<<mini<<endl;

	return 0;
}