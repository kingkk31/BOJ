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
int n, s, m, cache[101][2001];
vector<int> vt;

int solve(int pos, int sum)
{
	if (sum < 0 || sum > m)
		return -444444;
	if (pos >= n)
		return sum;
	
	int &ret = cache[pos][sum];
	if (ret != -1)
		return ret;
	ret = 0;

	ret = max(solve(pos + 1, sum + vt[pos]), solve(pos + 1, sum - vt[pos]));
	return ret;
}

int main(void)
{
	scanf("%d %d %d", &n, &s, &m);
	vt = vector<int>(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	memset(cache, -1, sizeof(cache));
	int ans = solve(0, s);
	cout << (ans < 0 ? -1 : ans) << endl;
	
	return 0;
}