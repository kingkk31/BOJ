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
int cache[202];
vector<int> vt;

int solve(int pos)
{
	if (pos > n)
		return 0;

	int &ret = cache[pos];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = pos + 1; i < vt.size(); i++)
		if (vt[pos] < vt[i])
			ret = max(ret, solve(i) + 1);
	
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	vt = vector<int>(n+2);
	vt[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &vt[i]);
	
	memset(cache, -1, sizeof(cache));
	printf("%d\n", n - solve(0));
	
	return 0;
}