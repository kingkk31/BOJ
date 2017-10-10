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
#define mk make_pair
int n, number;
vector<vector<int> > vt;
int visited[101][101];
vector<pair<int, int> > land;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
		return true;
	return false;
}

void init(int y, int x, int flag)
{
	vt[y][x] = flag;
	visited[y][x] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (isRange(ny, nx) && vt[ny][nx] == 1 && !visited[ny][nx])
			init(ny, nx, flag);
	}
}

bool isCoast(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (!isRange(ny, nx)) continue;
		if (vt[ny][nx] == 0)
			return true;
	}

	return false;
}

int bfs(int y, int x, int num)
{
	if (!isCoast(y, x)) return INF;
	
	queue<pair<pair<int, int>, int> > qu;
	qu.push(mk(mk(y, x), 0));

	while (!qu.empty())
	{
		int cy = qu.front().first.first, cx = qu.front().first.second, cost = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];

			if (!isRange(ny, nx) || visited[ny][nx] == 1 || vt[ny][nx] == num) continue;
			else if (vt[ny][nx] != num && vt[ny][nx] != 0) return cost;

			visited[ny][nx] = 1;
			qu.push(mk(mk(ny, nx), cost + 1));
		}
	}

	return INF;
}

int main(void)
{
	scanf("%d", &n);
	vt = vector<vector<int> >(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &vt[i][j]);
			if (vt[i][j] == 1) land.push_back(mk(i, j));
		}

	number = 1;
	for (int i = 0; i < land.size(); i++)
	{
		int y = land[i].first, x = land[i].second;
		if (!visited[y][x])
			init(land[i].first, land[i].second, number++);
	}

	int ans = INF;
	for (int i = 0; i < land.size(); i++)
	{
		memset(visited, 0, sizeof(visited));
		int y = land[i].first, x = land[i].second;
		ans = min(ans, bfs(y, x, vt[y][x]));
	}
	printf("%d\n", ans);

	return 0;
}