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

int n;
long long cache[65][10];

long long solve(int len, int pre)
{
	if (len == n)
		return 1;

	long long &ret = cache[len][pre];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = pre; i < 10; i++)
		ret += solve(len + 1, i);

	return ret;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> n;
		cout << solve(0, 0) << endl;
	}

	return 0;
}