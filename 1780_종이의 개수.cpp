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

int a, b, c;
vector<vector<int> > vt;

void solve(int y, int x, int len)
{
	int color = vt[y][x];
	bool flag = false;

	for (int i = y; i < y + len; i++)
		for (int j = x; j < x + len; j++)
			if (color != vt[i][j])
			{
				flag = true;
				break;
			}

	if (flag)
	{
		int nlen = len / 3;
		solve(y, x, nlen);
		solve(y, x + nlen, nlen);
		solve(y, x + (2 * nlen), nlen);
		solve(y + nlen, x, nlen);
		solve(y + nlen, x + nlen, nlen);
		solve(y + nlen, x + (2 * nlen), nlen);
		solve(y + (2 * nlen), x, nlen);
		solve(y + (2 * nlen), x + nlen, nlen);
		solve(y + (2 * nlen), x + (2 * nlen), nlen);
	}
	else
	{
		if (color == -1)
			a++;
		else if (color == 0)
			b++;
		else
			c++;
		return;
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	a = b = c = 0;
	vt = vector<vector<int> >(n, vector<int>(n));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &vt[i][j]);

	solve(0, 0, n);
	printf("%d\n%d\n%d\n", a, b, c);

	return 0;
}