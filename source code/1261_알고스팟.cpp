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
int n, m, cache[102][102];
vector<string> vt;
int dy[4] = { -1, 0, 0 ,1 };
int dx[4] = { 0, -1, 1, 0 };

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;
	return false;
}

int dijkstra()
{
	priority_queue<pair<int, pair<int, int> > > qu;
	qu.push(mk(0, mk(0, 0)));
	cache[0][0] = 0;

	while (!qu.empty())
	{
		int y = qu.top().second.first, x = qu.top().second.second, cost = -qu.top().first;
		qu.pop();

		if (cache[y][x] < cost)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (isRange(ny, nx))
			{
				if (vt[ny][nx] == '0' && cache[ny][nx] > cost)
				{
					cache[ny][nx] = cost;
					qu.push(mk(-cost, mk(ny, nx)));
				}
				else if (vt[ny][nx] == '1' && cache[ny][nx] > cost + 1)
				{
					cache[ny][nx] = cost + 1;
					qu.push(mk(-(cost + 1), mk(ny, nx)));
				}
			}
		}
	}

	return cache[n - 1][m - 1];
}

int main(void)
{
	scanf("%d %d", &m, &n);
	vt = vector<string>(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];

	for (int i = 0; i < 102; i++)
		for (int j = 0; j < 102; j++)
			cache[i][j] = INF;
	
	cout << dijkstra() << endl;

	return 0;
}