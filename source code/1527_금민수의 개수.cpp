#include <iostream>
#include <set>
#include <math.h>
using namespace std;

set<long long> data;

void makeNum(int n, long long sum)
{
	if (n == 0){
		data.insert(sum);
		return;
	}

	makeNum(n - 1, sum * 10 + 4);
	makeNum(n - 1, sum * 10 + 7);
}

int main()
{
	int n,m;

	cin >> n >> m;
	
	for (int i = 1; i <= 10;i++)
		makeNum(i, 0);

	set<long long>::iterator itLow = data.lower_bound(n);
	set<long long>::iterator itUp = data.upper_bound(m);

	int i = 0;

	for (set<long long>::iterator it = itLow; it != itUp; it++)
		i++;

	cout << i;

	return 0;	
}