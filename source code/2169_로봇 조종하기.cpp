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

int n, m;
vector<vector<vector<int> > > cache;
vector<vector<int> > vt;

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;
	return false;
}

int solve(int y, int x, int d)
{
	if (y == n-1 && x == m-1)
		return vt[y][x];

	int &ret = cache[y][x][d];
	if (ret != -200000000)
		return ret;
	
	int left = -200000000;
	if (isRange(y, x - 1) && d == 0)
		left = solve(y, x - 1, 0);

	int right = -200000000;
	if (isRange(y, x + 1) && d == 1)
		left = solve(y, x + 1, 1);

	int down = -200000000;
	if (isRange(y + 1, x))
		down = max(solve(y + 1, x, 1), solve(y + 1, x, 0));

	return ret = max(down, max(left, right)) + vt[y][x];
}

int main(void)
{
	scanf("%d %d", &n, &m);
	cache = vector<vector<vector<int> > >(1001, vector<vector<int> >(1001, vector<int>(2,-200000000)));
	vt = vector<vector<int> >(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &vt[i][j]);

	printf("%d\n", max(solve(0, 0, 1), solve(0, 0, 0)));

	return 0;
}
