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
int cache[1001][1001];

int solve(int n, int k)
{
	if (n == k || k == 0)
		return 1;

	int &ret = cache[n][k];
	if (ret != -1)
		return ret;
	ret = 0;

	ret = ((solve(n - 1, k - 1) % 10007) + (solve(n - 1, k) % 10007)) % 10007;
	return ret;
}

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	memset(cache, -1, sizeof(cache));
	cout << solve(N, K) << endl;
	
	return 0;
}