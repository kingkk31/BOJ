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
int n;
long long cache[101][21];
vector<int> vt;

long long solve(int pos, int sum)
{
	if (pos < 0 || sum < 0 || sum > 20)
		return 0;
	if (pos == 1 && sum == vt[1])
		return 1;
	
	long long &ret = cache[pos][sum];
	if (ret != -1)
		return ret;
	ret = 0;

	ret = solve(pos - 1, sum + vt[pos]) + solve(pos - 1, sum - vt[pos]);
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	vt = vector<int>(n + 1);
	vt[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &vt[i]);

	memset(cache, -1LL, sizeof(cache));
	cout << solve(n - 1, vt[n]) << endl;
	
	return 0;
}