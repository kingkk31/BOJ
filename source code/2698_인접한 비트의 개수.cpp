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
int n, k, cache[100][100][2];

int solve(int len, int cnt, int flag)
{
	if (len == n)
	{
		if (cnt == k)
			return 1;
		else
			return 0;
	}

	int &ret = cache[len][cnt][flag];
	if (ret != -1) return ret;
	ret = 0;

	if (flag == 1)
		ret += solve(len + 1, cnt + 1, 1) + solve(len + 1, cnt, 0);
	else
		ret += solve(len + 1, cnt, 0) + solve(len + 1, cnt, 1);

	return ret;
}

int main(void)
{
	int t;	scanf("%d", &t);
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		scanf("%d %d", &n, &k);
		cout << solve(1, 0, 1) + solve(1, 0, 0) << endl;
	}

	return 0;
}