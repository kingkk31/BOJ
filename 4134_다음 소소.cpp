#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

bool isPrime(long long n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int sqrtn = int(sqrt((double)n));
	for (int i = 3; i <= sqrtn; i += 2)
		if (n%i == 0)
			return false;

	return true;
}

int main(void)
{
	int n;
	cin >> n;

	for (int a = 0; a < n; a++)
	{
		long long num;
		cin >> num;

		long long cnt = num;

		while (1)
		{
			if (isPrime(cnt))
				break;
			cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}