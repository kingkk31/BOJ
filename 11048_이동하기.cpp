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

int dy[3] = { 1, 0, 1 };
int dx[3] = { 0, 1, 1 };
int cache[1001][1001];
int n, m;
vector<vector<int> > vt;

bool isRange(int y, int x)
{
	if (1 <= y && y <= n && 1 <= x && x <= m)
		return true;
	return false;
}

int solve(int y, int x)
{
	if (y == n && x == m)
		return vt[y][x];
	
	int &ret = cache[y][x];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isRange(ny, nx))
			ret = max(ret, solve(ny, nx) + vt[y][x]);
	}

	return ret;
}

int main(void)
{
	cin >> n >> m;
	vt = vector<vector<int> >(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &vt[i][j]);

	memset(cache, -1, sizeof(cache));
	cout << solve(1, 1) << endl;
	
	return 0;
}