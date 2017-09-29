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
int cache[1001][3][4];

int solve(int len, int l, int a)
{
	if (len == n)
		return 1;

	int &ret = cache[len][l][a];
	if (ret != -1)
		return ret;
	ret = 0;

	ret = (ret + (solve(len + 1, l, 0) % 1000000)) % 1000000;
	if (l < 1)
		ret = (ret + (solve(len + 1, l + 1, 0) % 1000000)) % 1000000;
	if (a < 2)
		ret = (ret + (solve(len + 1, l, a + 1) % 1000000)) % 1000000;
	return ret;
}

int main(void)
{
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << solve(0, 0, 0) << endl;

	return 0;
}