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
int l;
vector<vector<int> > cache;
int dy[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dx[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

bool isRange(int y, int x)
{
	if (0 <= y && y < l && 0 <= x && x < l)
		return true;
	return false;
}

void bfs(int y, int x)
{
	queue<pair<int, int> > qu;
	qu.push(make_pair(y, x));
	cache[y][x] = 0;

	while (!qu.empty())
	{
		int py = qu.front().first;
		int px = qu.front().second;
		qu.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = py + dy[i];
			int nx = px + dx[i];

			if (isRange(ny, nx) && cache[ny][nx] > cache[py][px] + 1)
			{
				cache[ny][nx] = cache[py][px] + 1;
				qu.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--) 
	{
		scanf("%d", &l);
		cache = vector<vector<int> >(301, vector<int>(301, INF));
		
		int y1, x1, y2, x2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		bfs(y1, x1);
		printf("%d\n", cache[y2][x2]);
	}

	return 0;
}