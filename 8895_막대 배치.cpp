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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define LL long long
int n, l, r;
LL cache[101][101][101];

LL solve(int a, int b, int c)
{
	if(b == 1 && c == 1)
		return a == 1 ? 1 : 0;
	else if (b < 1 || c < 1 || b + c > a + 1) 
		return 0;
		
	LL &ret = cache[a][b][c];
	if (ret != -1)
		return ret;
	ret = 0;

	return ret = (solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) + (solve(a - 1, b, c)*(a - 2)));
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) 
	{
		cin >> n >> l >> r;
		memset(cache, -1, sizeof(cache));
		cout << solve(n, l, r) << endl;
	}

	return 0;
}