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
int n, t, cache[101][10001];
vector<pair<int, int> > vt;

int solve(int pos, int time)
{
	if (pos == n)
		return 0;
	
	int &ret = cache[pos][time];
	if (ret != -1) return ret;
	ret = 0;

	if (time - vt[pos].first >= 0)
		ret = max(solve(pos + 1, time), solve(pos + 1, time - vt[pos].first) + vt[pos].second);
	else
		ret = solve(pos + 1, time);
	
	return ret;
}

int main(void)
{
	scanf("%d %d", &n, &t);
	vt = vector<pair<int, int> >(n);
	for (int i = 0; i < n; i++)
	{
		int k, s;
		scanf("%d %d", &k, &s);
		vt[i] = make_pair(k, s);
	}

	memset(cache, -1, sizeof(cache));
	cout << solve(0, t) << endl;

	return 0;
}