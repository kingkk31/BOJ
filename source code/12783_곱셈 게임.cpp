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
int cache[1000001];
int mask;

int solve(int k)
{
	int &ret = cache[k];
	if (ret != -1)
		return ret;
	
	int temp = 0;
	for (int num = k; num; num /= 10)
		temp |= (1 << (num % 10));

	if ((mask & temp) == temp)
		return ret = 0;

	ret = INF;
		
	for (int i = 2; i * i <= k; i++)
		if (k % i == 0)
			ret = min(ret, solve(i) + solve(k / i) + 1);
	
	return ret;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		mask = 0;

		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int num;
			scanf("%d", &num);
			mask |= (1 << num);
		}
	
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int k, result = INF;
			scanf("%d", &k);
			result = solve(k);
			printf("%d\n", (result == INF ? -1 : result));
		}
	}

	return 0;
}