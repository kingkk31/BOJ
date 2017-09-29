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
int N;
int vt[501];
int cache[501][501];
int sum[501];

int solve(int s, int e)
{
	if (s + 1 == e)
		return sum[e + 1] - sum[s];
	
	if (s == e)
		return 0;

	int& ret = cache[s][e];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = s; i < e; i++)
		ret = min(ret, solve(s, i) + solve(i + 1, e) + sum[e + 1] - sum[s]);

	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &vt[i]);

		memset(cache, -1, sizeof(cache));

		sum[0] = 0;
		for (int i = 1; i <= N; i++)
			sum[i] = sum[i - 1] + vt[i - 1];

		printf("%d\n", solve(0, N - 1));
	}
	return 0;
}