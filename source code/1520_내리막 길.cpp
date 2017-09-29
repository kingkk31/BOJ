#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
vector<vector<int> > vt;
int cache[501][501];

bool isRange(int y, int x)
{
	if (0 <= y&& y < n && 0 <= x && x < m)
		return true;

	return false;
}

int down(int y, int x)
{
	if (y == n - 1 && x == m - 1)
		return 1;

	int &ret = cache[y][x];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isRange(ny, nx) && vt[y][x] > vt[ny][nx])
			ret += down(ny, nx);
	}

	return ret;
}

int main(void)
{
	cin >> n >> m;

	memset(cache, -1, sizeof(cache));
	vt = vector<vector<int> >(n+1, vector<int>(m+1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> vt[i][j];

	cout << down(0, 0) << endl;

	return 0;
}