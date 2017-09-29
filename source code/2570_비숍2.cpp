#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <assert.h>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int N;
bool adj[1001][1001];
vector<int> aMatch, bMatch;
vector<bool> visited;

const int dy[2] = { 1, 1 };
const int dx[2] = { -1, 1 };
vector<vector<int> > board;
int id[2][1001][1001];

bool inRange(int y, int x)
{
	if (0 <= y < N && 0 <= x < N)
		return true;
	return false;
}

bool dfs(int a)
{
	if (visited[a])
		return false;

	visited[a] = true;

	for (int b = 0; b < m; ++b)
	{
		if (adj[a][b])
		{
			if (bMatch[b] == -1 || dfs(bMatch[b]))
			{
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}

	return false;
}

int bipartitiedMatch()
{
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);

	int size = 0;

	for (int start = 0; start < n; ++start)
	{
		visited = vector<bool>(n, false);

		if (dfs(start))
			++size;
	}

	return size;
}

int placeBishops(void)
{
	memset(id, -1, sizeof(id));
	int count[2] = { 0,0 };

	for (int dir = 0; dir < 2; ++dir)
		for (int y = 0; y < N; ++y)
			for (int x = 0; x < N; ++x)
				if (board[y][x] == 0 && id[dir][y][x] == -1)
				{
					int cy = y, cx = x;

					while (0 <= cy && cy < N && 0 <= cx && cx < N && board[cy][cx] == 0)
					{
						id[dir][cy][cx] = count[dir];
						cy += dy[dir];
						cx += dx[dir];
					}
					count[dir]++;
				}

	n = count[0];
	m = count[1];

	memset(adj, 0, sizeof(adj));
	
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			if (board[y][x] == 0)
				adj[id[0][y][x]][id[1][y][x]] = 1;

	return bipartitiedMatch();
}

int main(void)
{
	cin >> N;
	
	board = vector<vector<int> >(N + 1, vector<int>(N + 1, 0));

	int block;
	cin >> block;

	for (int i = 0; i < block; i++)
	{
		int y, x;
		cin >> y >> x;
		board[y - 1][x - 1] = 1;
	}

	cout << placeBishops() << endl;

	return 0;
}