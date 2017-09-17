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
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321
int n;
int cache[1001];

int solve(int pos, vector<int> vt)
{
	if (pos == n - 1)
		return 0;

	int &ret = cache[pos];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = 1; i <= vt[pos]; i++)
	{
		if (pos + i < n)
			ret = min(ret, solve(pos + i, vt) + 1);
	}

	return ret;
}

int main(void)
{
	cin >> n;

	memset(cache, -1, sizeof(cache));
	vector<int> vt(n);

	for (int i = 0; i < n; i++)
		cin >> vt[i];

	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	int result = solve(0, vt);

	if (result == INF)
		cout << -1 << endl;
	else
		cout << result << endl;

	return 0;
}