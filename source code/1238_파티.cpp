#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int n;
const int INF = 987654321;
vector<pair<int, int> > vt[1001];
priority_queue<pair<int, int> > qu;
vector<vector<int> > total;

void dijkstra(int from)
{
	total[from][from] = 0;
	qu.push(make_pair(0, from));

	while (!qu.empty())
	{
		int cost = -qu.top().first;
		int here = qu.top().second;
		qu.pop();

		if (total[from][here] < cost)
			continue;

		for (int j = 0; j < vt[here].size(); j++)
		{
			int next = vt[here][j].first;
			int nextCost = cost + vt[here][j].second;

			if (total[from][next] > nextCost)
			{
				total[from][next] = nextCost;
				qu.push(make_pair(-nextCost, next));
			}
		}
	}
}

int main(void)
{
	int m, x;
	scanf("%d %d %d", &n, &m, &x);

	total = vector<vector<int> >(1001, vector<int>(1001, INF));

	for (int i = 0; i < m; i++)
	{
		int f, t, c;
		scanf("%d %d %d", &f, &t, &c);

		vt[f - 1].push_back(make_pair(t - 1, c));
	}

	for (int i = 0; i < n; i++)
		dijkstra(i);
		
	int maxi = -1;

	for (int i = 0; i < n; i++)
		maxi = max(maxi, total[i][x - 1] + total[x - 1][i]);
	
	printf("%d\n", maxi);

	return 0;
}
