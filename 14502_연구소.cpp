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

int n, m, maxi;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
vector<vector<int> > vt;
vector<vector<bool> > visited;
vector<pair<int, int> > virus;

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;
	return false;
}

void bfs()
{
	queue<pair<int, int> > qu;
	for (int i = 0; i < virus.size(); i++)
		qu.push(virus[i]);

	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (isRange(ny, nx) && vt[ny][nx] == 0)
			{
				vt[ny][nx] = 4;
				qu.push(make_pair(ny, nx));
			}
		}
	}
}

void dfs(int y, int x, int cnt)
{
	vt[y][x] = 1;
	visited[y][x] = true;

	if (cnt == 3)
	{
		bfs();
		
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (vt[i][j] == 0)
					temp++;
				else if (vt[i][j] == 4)
					vt[i][j] = 0;
			}
		}
		maxi = max(maxi, temp);
		
		vt[y][x] = 0;
		visited[y][x] = false;
		return;
	}

	for (int i = y; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j] && vt[i][j] == 0)
				dfs(i, j, cnt + 1);

	vt[y][x] = 0;
	visited[y][x] = false;
}

int main(void)
{
	maxi = 0;
	scanf("%d %d", &n, &m);

	visited = vector<vector<bool> >(n, vector<bool>(m, false));
	vt = vector<vector<int> >(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &vt[i][j]);
			if (vt[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if(vt[i][j] == 0)
				dfs(i, j, 1);

	printf("%d\n", maxi);

	return 0;
}