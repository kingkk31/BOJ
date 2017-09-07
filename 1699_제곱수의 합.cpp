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
int cache[100001];

int solve(int pos)
{
	if (pos <= 0)
		return 0;

	int &ret = cache[pos];
	if (ret != -1)
		return ret;
	ret = INF;

	for (int i = 1; i*i <= pos; i++)
		if (ret > solve(pos - i*i) + 1)
			ret = solve(pos - i*i) + 1;
	
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(n));

	return 0;
}