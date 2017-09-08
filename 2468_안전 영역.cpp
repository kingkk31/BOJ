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
#pragma warning(disable:4996)
using namespace std;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
int n, maxi;

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
		return true;
	return false;
}

int dfs(vector<vector<int> > &temp, int y, int x)
{
	temp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isRange(ny, nx) && temp[ny][nx] != 0)
			dfs(temp, ny, nx);
	}

	return 1;
}

int solve(vector<vector<int> > vt)
{
	int cnt = 0;
	vector<vector<int> > temp = vt;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (temp[i][j] != 0)
				cnt += dfs(temp, i, j);

	return cnt;
}

int main(void)
{
	maxi = -1;
	cin >> n;
	
	int ground = 0;
	vector<vector<int> > vt(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &vt[i][j]);
			if (vt[i][j] != 0)
				ground++;
		}

	while (true)
	{
		if (ground == 0)
			break;

		int cnt = solve(vt);
		maxi = max(maxi, cnt);
	
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (vt[i][j] == 0)
					continue;
				vt[i][j]--;
				if (vt[i][j] == 0)
					ground--;
			}
	}

	cout << maxi << endl;

	return 0;
}