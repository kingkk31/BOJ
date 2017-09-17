#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	cin>>N;

	vector<int> vt;
	int cnt = 0;

	for(int i=0;i<N;i++)
	{
		int num;
		cin>>num;
		vt.push_back(num);
	}

	int check;
	cin>>check;
	
	for(int i=0;i<N;i++)
		if(vt[i] == check)
			cnt++;

	cout<<cnt<<endl;

	return 0;
} 