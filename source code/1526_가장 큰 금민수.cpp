#include <iostream>
#include <set>
#include <math.h>
using namespace std;

int fs[] = { 4, 7 };

set<int> data;

void makeNum(int n, int sum)
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
	int n;

	cin >> n;
	
	for (int i = 1; i <= 6;i++)
		makeNum(i, 0);

	set<int>::iterator it = data.upper_bound(n);

	if (it != data.begin())
		cout << *(--it);

	return 0;
}