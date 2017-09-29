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
int cache[10001][21];
vector<int> vt;

int solve(int cost, int pos)
{
	if (cost < 0)
		return 0;

	if (cost == 0)
		return 1;
	
	int &ret = cache[cost][pos];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = pos; i < vt.size(); i++)
		ret += solve(cost - vt[i], i);
	
	return ret;
}

int main(void)
{
	int t;
	scanf("%d", &t);

	while (t--) 
	{
		scanf("%d", &n);
		vt = vector<int>(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &vt[i]);
		
		int m;
		scanf("%d", &m);
		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve(m, 0));
	}
	return 0;
}