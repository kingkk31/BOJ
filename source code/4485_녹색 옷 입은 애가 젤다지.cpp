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
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
vector<vector<int> > vt;

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
		return true;
	return false;
}

int daijkstra(int fromi, int fromj, int toi, int toj)
{
	vector<vector<int> > total(n, vector<int>(n, INF));
	priority_queue<pair<int, pair<int, int> > > qu;

	total[fromi][fromj] = vt[fromi][fromj];
	qu.push(make_pair(-total[fromi][fromj], make_pair(fromi, fromj)));

	while (!qu.empty())
	{
		int cost = -qu.top().first;
		pair<int, int> here = qu.top().second;
		qu.pop();

		if (total[here.first][here.second] < cost)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int nextY = here.first + dy[i];
			int nextX = here.second + dx[i];
			
			if (isRange(nextY, nextX) && total[nextY][nextX] > cost + vt[nextY][nextX])
			{
				total[nextY][nextX] = cost + vt[nextY][nextX];
				qu.push(make_pair(-(cost + vt[nextY][nextX]), make_pair(nextY, nextX)));
			}
		}
	}

	return total[toi][toj];
}


int main(void)
{
	int t = 0;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;

		vt = vector<vector<int> >(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &vt[i][j]);

		cout << "Problem " << ++t << ": " << daijkstra(0, 0, n - 1, n - 1) << endl;
	}
	
	return 0;
}