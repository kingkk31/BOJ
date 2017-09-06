#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> vt;

void make(long long num)
{
	if(num > 9876543210)
		return;

	vt.push_back(num);
	long long down = num % 10;
	
	for (long long i = down - 1; i >= 0; --i)
		make((num*10) + i);
}

int main(void)
{
	int n;
	cin>>n;
	
	vt.push_back(0);

	for(int i=1;i<10;i++)
		make(i);

	sort(vt.begin(), vt.end());

	if(vt.size() <= n)
		cout<<-1<<endl;
	else
		cout<<vt[n]<<endl;

	return 0;
}