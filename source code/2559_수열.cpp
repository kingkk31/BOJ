#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N,K;
	cin>>N>>K;
	vector<int> vt;

	for(int i=0;i<N;i++)
	{	
		int num;
		cin>>num;
		vt.push_back(num);
	}

	int max;
	int total=0;

	for(int i=0;i<K;i++)
		total += vt[i];
	
	max = total;

	for(int i=K;i<vt.size();i++)
	{
		total += vt[i];
		total -= vt[i-K];
		if(total > max)
			max = total;
	}

	cout<<max<<endl;

	return 0;
}