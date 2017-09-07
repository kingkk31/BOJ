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

vector<string> vt;
int n, m, maxi;
int cache[1001][1001];

int solve(int y, int x)
{
	if ((y < 0 || x < 0))
		return 0;

	int &ret = cache[y][x];
	if (ret != -1)
		return ret;
	ret = 0;

	int a, b, c;
	a = solve(y - 1, x - 1);
	b = solve(y, x - 1);
	c = solve(y - 1, x);

	if (vt[y][x] == '0')
		ret = 0;
	else if(a == 0 || b == 0 || c == 0)
		ret = 1;	
	else 
	{
		if (a == b && b == c)
			ret = a + 1;
		else
			ret = min(a, min(b, c)) + 1;
	}

	maxi = max(maxi, ret);
	
	return ret;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	vt = vector<string>(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];
	memset(cache, -1, sizeof(cache));
	maxi = 0;

	solve(n - 1, m - 1);
	cout << maxi * maxi << endl;

	return 0;
}