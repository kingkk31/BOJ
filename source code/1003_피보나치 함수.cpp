#include <iostream>
#include <utility>
#include <vector>
using namespace std;

pair<int,int> operator+(pair<int,int> left, pair<int,int> right)
{
	left.first += right.first;
	left.second += right.second;

	return left;
}

pair<int,int> fibonacci(vector<pair<int,int> > &vt, int n)
{
	if(n < vt.size())
		return vt[n];

	vt.push_back(fibonacci(vt,n-1) + fibonacci(vt,n-2));

	return vt[n];
}


int main(void)
{
	int T;
	cin>>T;

	vector<pair<int,int> > vt;
	pair<int,int> fibo1(1,0);
	pair<int,int> fibo2(0,1);
	vt.push_back(fibo1);
	vt.push_back(fibo2);

	//기본 초기화

	for(int i=0;i<T;i++)
	{
		int n;
		cin>>n;

		fibonacci(vt,n);
	
		cout<< vt[n].first << " " << vt[n].second << endl;
	}

    return 0;
}