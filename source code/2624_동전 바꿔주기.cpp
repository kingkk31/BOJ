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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int t, k, cache[1002][10002];
vector<int> p, n;

int solve(int pos, int money)
{
	if (money == 0)
		return 1;
	if (pos >= k)
		return 0;

	int &ret = cache[pos][money];
	if (ret != -1) return ret; ret = 0;

	for (int i = n[pos]; i >= 0; i--)
		if (money - (p[pos] * i) >= 0)
			ret += solve(pos + 1, money - (p[pos] * i));
	
	return ret;
}

int main(void)
{
	scanf("%d %d", &t, &k);
	p = vector<int>(k);	n = vector<int>(k);
	for (int i = 0; i < k; i++)
		scanf("%d %d", &p[i], &n[i]);

	memset(cache, -1, sizeof(cache));
	int ans = solve(0, t);
	printf("%d\n", ans);
		
	return 0;
}