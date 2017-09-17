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

#define INF 987654321
int cache[501][501];
vector<int> vt;

int solve(int s, int e)
{
	if (s == e)
		return 0;

	int &ret = cache[s][e];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = s; i < e; i++)
		ret = min(ret, (solve(s, i) + solve(i + 1, e) + vt[s-1] * vt[i] * vt[e]));

	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	vt = vector<int>(n + 1);
	memset(cache, -1, sizeof(cache));
	
	for (int i = 0; i < n;i++)
	{
		int r, c;
		cin >> r >> c;
		vt[i] = r;
		vt[i + 1] = c;
	}
	cout << solve(1, n) << endl;

	return 0;
}