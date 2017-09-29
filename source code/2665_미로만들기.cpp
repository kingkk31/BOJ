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

#define INF 987654321
#define pp pair<int, int>
#define mk make_pair
int n;
int dy[4] = { -1, 0, 0 ,1 };
int dx[4] = {0, -1, 1, 0};
vector<string> vt;
vector<vector<int> > cache;

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
		return true;
	return false;
}

int bfs()
{
	queue<pp> qu;
	qu.push(mk(0, 0));
	cache[0][0] = 0;

	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();
		int wall = cache[y][x];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (isRange(ny, nx))
			{
				if (vt[ny][nx] == '1' && cache[ny][nx] > wall)
				{
					cache[ny][nx] = wall;
					qu.push(mk(ny, nx));
				}
				else if (vt[ny][nx] == '0' && cache[ny][nx] > wall + 1)
				{
					cache[ny][nx] = wall + 1;
					qu.push(mk(ny, nx));
				}
			}
		}
	}

	return cache[n - 1][n - 1];
}

int main(void)
{
	cin >> n;
	vt = vector<string>(n);
	cache = vector<vector<int> >(n, vector<int>(n, INF));

	for (int i = 0; i < n; i++)
		cin >> vt[i];

	cout << bfs() << endl;

	return 0;
}