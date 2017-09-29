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
int cache[2][1001][1001];
vector<int> vt;

int solve(int player, int start, int end)
{
	if (start == end)
	{
		if (player)
			return vt[start];
		else
			return 0;
	}

	int &ret = cache[player][start][end];
	if (ret != -1)
		return ret;
	ret = 0;

	if(player)
		ret = max(solve(!player, start + 1, end) + vt[start], solve(!player, start, end - 1) + vt[end]);
	else
		ret = min(solve(!player, start + 1, end), solve(!player, start, end - 1));

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
	
		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve(1, 0, n - 1));
	}

	return 0;
}