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
int cache[1002];
vector<int> vt;

int solve(int b)
{
	if (b == 0)
		return 0;

	int &ret = cache[b];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = 1; i <= n; i++)
		if (b - i >= 0) 
			ret = max(ret, solve(b - i) + vt[i]);
	
	return ret;
}


int main(void)
{
	scanf("%d", &n);
	vt = vector<int>(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &vt[i]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(n));

	return 0;
}