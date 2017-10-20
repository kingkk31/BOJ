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
int n, m, cache[1001][1001][2];
vector<string> vt;
int dy[4] = { -1, 0, 0 ,1 };
int dx[4] = { 0, -1, 1, 0 };

typedef struct Node {
	int y, x, d, flag;

	Node(int _y, int _x, int _d, int _flag) : y(_y), x(_x), d(_d), flag(_flag) {}
};

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;
	return false;
}

int bfs()
{
	queue<Node> qu;
	qu.push(Node(0, 0, 1, 0));
	cache[0][0][0] = 1;

	while (!qu.empty())
	{
		int y = qu.front().y, x = qu.front().x, cost = qu.front().d, flag = qu.front().flag ;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (isRange(ny, nx))
			{
				if (vt[ny][nx] == '1')
				{
					if (flag == 0 && cache[ny][nx][0] > cost + 1)
					{
						cache[ny][nx][1] = cost + 1;
						qu.push(Node(ny, nx, cost + 1, 1));
					}
				}
				else if (vt[ny][nx] == '0' && cache[ny][nx][flag] > cost + 1)
				{
					cache[ny][nx][flag] = cost + 1;
					qu.push(Node(ny, nx, cost + 1, flag));
				}
			}
		}
	}

	return min(cache[n - 1][m - 1][0], cache[n - 1][m - 1][1]);
}

int main(void)
{
	scanf("%d %d", &n, &m);
	vt = vector<string>(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];

	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			cache[i][j][0] = cache[i][j][1] = INF;

	int ans = bfs();
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}