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
int n;
vector<string> vt;
vector<string> vt2;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
		return true;
	return false;
}

int dfs(int y, int x)
{
	char pos = vt[y][x];
	vt[y][x] = 'A';

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isRange(ny, nx) && vt[ny][nx] != 'A' && vt[ny][nx] == pos)
			dfs(ny, nx);
	}

	return 1;
}

int dfs2(int y, int x)
{
	char pos = vt2[y][x];
	vt2[y][x] = 'A';

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isRange(ny, nx) && vt2[ny][nx] != 'A')
			if ((pos == 'R' || pos == 'G') && (vt2[ny][nx] == 'R' || vt2[ny][nx] == 'G'))
				dfs2(ny, nx);
			else if (pos == 'B' && vt2[ny][nx] == 'B')
				dfs2(ny, nx);
	}
	
	return 1;
}

int main(void)
{
	scanf("%d", &n);
	vt = vector<string>(n);
	vt2 = vector<string>(n);

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vt[i] = vt2[i] = str;
	}

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(vt[i][j] != 'A')
				ans1 += dfs(i, j);
			if (vt2[i][j] != 'A')
				ans2 += dfs2(i, j);
		}
	}

	printf("%d %d\n", ans1, ans2);

	return 0;
}