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
int n, m, k;
vector<vector<char> > vt;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;
	return false;
}

int dfs(int y, int x)
{
	char pos = vt[y][x];
	vt[y][x] = '.';

	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isRange(ny, nx) && vt[ny][nx] == '#')
			cnt += dfs(ny, nx);
	}

	return cnt;
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &k);
	vt = vector<vector<char> >(n, vector<char>(m, '.'));
	while (k--)
	{
		int y, x;
		scanf("%d %d", &y, &x);
		vt[y - 1][x - 1] = '#';
	}

	int maxi = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (vt[i][j] == '#')
				maxi = max(maxi, dfs(i, j));
	printf("%d\n", maxi);

	return 0;
}