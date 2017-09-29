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
int cache[1003];
int cache2[1003];
vector<int> vt;

int solve(int pos)
{
	if (pos > n)
		return 0;

	int &ret = cache[pos];
	if (ret != -1)
		return ret;
	ret = 1;

	for (int i = pos + 1; i < vt.size(); i++)
		if (vt[pos] > vt[i])
			ret = max(ret, solve(i) + 1);
	
	return ret;
}

int solve2(int pos)
{
	if (pos < 1)
		return 0;

	int &ret = cache2[pos];
	if (ret != -1)
		return ret;
	ret = 1;

	for (int i = pos - 1; i > 0; i--)
		if (vt[pos] > vt[i])
			ret = max(ret, solve2(i) + 1);

	return ret;
}

int main(void)
{
	scanf("%d", &n);
	vt = vector<int>(n+2);
	vt[0] = 0;
	vt[n + 1] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &vt[i]);
	
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	
	for(int i=0;i<=n;i++)
		solve(i);
	for(int i=n+1;i>0;i--)
		solve2(i);

	int maxi = 0;
	for (int i = 1; i <= n; i++)
		maxi = max(maxi, cache[i] + cache2[i] - 1);
	
	printf("%d\n", maxi);
	
	return 0;
}