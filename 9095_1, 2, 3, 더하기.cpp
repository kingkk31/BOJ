#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#include <time.h>
#include <cctype>
#pragma warning(disable:4996)
using namespace std;
 
int cache[12];

int solve(int n)
{
	if (n == 0)
		return 1;
	else if (n < 0)
		return 0;

	if (cache[n] != -1)
		return cache[n];

	cache[n] = 0;

	for (int i = 3; i > 0; i--)
		cache[n] += solve(n - i);

	return cache[n];
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		memset(cache, -1, sizeof(cache));
		cout << solve(n) << endl;
	}

    return 0;
}