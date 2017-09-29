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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int m, n;
vector<vector<int> > vt;

bool isRange(int y, int x)
{
	if (0 <= y && y < m && 0 <= x && x < n)
		return true;
	return false;
}

int dfs(int y, int x)
{
	vt[y][x] = 2;

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (isRange(ny, nx) && vt[ny][nx] == 1)
			dfs(ny, nx);
	}

	return 1;
}

int main(void)
{
	scanf("%d %d", &m, &n);
	vt = vector<vector<int> >(m, vector<int>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &vt[i][j]);

	int cnt = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (vt[i][j] == 1)
				cnt += dfs(i, j);
	cout << cnt << endl;

	return 0;
}