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

int solve(int num)
{
	if (num == 1)
		return 0;

	int &ret = cache[num];
	if (ret != -1)
		return ret;
	ret = INF;

	ret = min(ret, solve(num - 1) + 1);
	if (num % 3 == 0)
		ret = min(ret, solve(num / 3) + 1);
	if (num % 2 == 0)
		ret = min(ret, solve(num / 2) + 1);

	return ret;
}

int main(void)
{
	int m;
	scanf("%d", &m);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(m));

	return 0;
}