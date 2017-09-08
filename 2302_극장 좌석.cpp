#include <iostream>
#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int cache[41];

void fibo(void)
{
	cache[0] = 1; cache[1] = 1, cache[2] = 2;
	int a = 1, b = 2;

	for (int i = 1; i < 40; i++)
		cache[i + 2] = cache[i] + cache[i + 1];
}

int main(void)
{
	int n,m,cnt=1;
	fibo();
	cin >> n >> m;

	vector<int> seat;
	seat.push_back(0);
	for (int i = 0; i < m; i++)
	{
		int vip;
		cin >> vip;
		seat.push_back(vip);
	}
	seat.push_back(n+1);

	for (int i = 0; i < seat.size()-1; i++)
		cnt *= cache[seat[i+1]-seat[i]-1];
	
	cout << cnt << endl;
	
	return 0;
}