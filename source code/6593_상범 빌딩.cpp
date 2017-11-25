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
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int l, r, c;
int dy[6] = { 0, 0, -1, 0, 0 , 1 };
int dx[6] = { 0, 0, 0, -1, 1 , 0 };
int dz[6] = { -1, 1, 0, 0, 0 , 0 };
vector<vector<string> > building;

struct pos {
	int x, y, z;

	pos(int _z, int _y, int _x)
	{
		z = _z;
		y = _y;
		x = _x;
	}
};

bool isRange(int z, int y, int x)
{
	if (0 <= z && z < l && 0 <= y && y < r && 0 <= x && x < c)
		return true;
	return false;
}

int bfs(pos from, pos to)
{
	vector<vector<vector<int > > > cache(l, vector<vector<int> >(r, vector<int>(c, INF)));
	queue<pair<int, pos> > qu;

	cache[from.z][from.y][from.x] = 0;
	qu.push(make_pair(0, from));

	while (!qu.empty())
	{
		int cost = qu.front().first;
		pos here = qu.front().second;
		qu.pop();

		if (cache[here.z][here.y][here.x] < cost)
			continue;

		for (int i = 0; i < 6; i++)
		{
			int nextZ = here.z + dz[i], nextY = here.y + dy[i], nextX = here.x + dx[i];

			if (isRange(nextZ, nextY, nextX)  && (building[nextZ][nextY][nextX] == '.' || building[nextZ][nextY][nextX] == 'S' || building[nextZ][nextY][nextX] == 'E') && cache[nextZ][nextY][nextX] > cost + 1)
			{
				cache[nextZ][nextY][nextX] = cost + 1;
				qu.push(make_pair(cost + 1, pos(nextZ, nextY, nextX)));
			}
		}
	}

	return cache[to.z][to.y][to.x];
}

int main(void)
{
	while (true)
	{
		scanf("%d %d %d", &l, &r, &c);
		if (l == 0 && r == 0 && c == 0) break;
		
		building = vector<vector<string> >(l, vector<string>(r));
		pos from(0, 0, 0), to(0, 0, 0);

		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
			{
				cin >> building[i][j];
				for (int k = 0; k < c; k++)
				{
					if (building[i][j][k] == 'S')
						from.z = i, from.y = j, from.x = k;
					
					if (building[i][j][k] == 'E')
						to.z = i, to.y = j, to.x = k;
				}
			}

		int ans = bfs(from, to);
		if (ans == INF)
			cout << "Trapped!" << endl;
		else
			printf("Escaped in %d minute(s).\n", ans);
	}

	return 0;
}