#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

long long cache[5001][5001];
int L;

long long solve(int l, int left)
{
	if (left < 0)
		return 0;
	
	if (l == 0)
	{	
		if (left == 0)
			return 1;
		else
			return 0;
	}

	long long &ret = cache[l][left];

	if (ret != -1)
		return ret % 1000000007;

	ret = 0;

	ret = (ret + solve(l - 1, left + 1)) % 1000000007;
	ret = (ret + solve(l - 1, left - 1)) % 1000000007;
	
	return ret % 1000000007;
}

int main(void)
{
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;

	while (t--)
	{
		cin >> L;

		if (L % 2 != 0)
		{
			cout << 0 << endl;
			continue;
		}

		cout << solve(L, 0) % 1000000007 << endl;
	}

	return 0;
}