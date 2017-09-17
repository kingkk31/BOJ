#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	cin>>N;
	
	int first;
	cin>>first;

	int mini = first, maxi = first; 

	for(int i=0;i<N-1;i++)
	{
		int num;
		cin>>num;
		
		mini = min(mini, num);
		maxi = max(maxi, num);
	}

	cout<<mini<<" "<<maxi<<endl;

	return 0;
} 