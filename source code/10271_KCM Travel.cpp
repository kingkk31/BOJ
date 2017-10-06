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

typedef struct edge {
	int v, c, d;
	edge(int _v, int _c, int _d) : v(_v), c(_c), d(_d) {}
	edge() {}
};

typedef struct EdgeCompare {
	bool operator()(const edge& lhs, const edge& rhs) const {
		if (lhs.d > rhs.d)
			return true;
		else if (lhs.d == rhs.d && lhs.c > rhs.c)
			return true;
		return false;
	}
};

int n, m, k, result, cache[100][10005];
vector<vector<edge> > graph;

void dijstra()
{
	priority_queue<edge, vector<edge>, EdgeCompare > q;
	for (int i = 0; i < graph[0].size(); i++)
		q.push(graph[0][i]);

	while (!q.empty())
	{
		int v, c, d;
		v = q.top().v;
		c = q.top().c;
		d = q.top().d;
		q.pop();

		if (cache[v][c] < d) continue;
		cache[v][c] = d;

		for (int i = 0; i < graph[v].size(); i++)
		{
			int nV = graph[v][i].v, nC = graph[v][i].c, nD = graph[v][i].d;
			if (c + nC <= m && cache[nV][c + nC] > d + nD)
			{
				q.push(edge(nV, c + nC, d + nD));
				cache[nV][c + nC] = d + nD;
			}
		}
	}
}

int main(void)
{
	int t;
	cin >> t;

	for (int z = 0; z < t; z++)
	{
		cin >> n >> m >> k;
		result = INF;

		graph.clear();
		graph.assign(n, vector<edge>());
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 10005; j++)
				cache[i][j] = INF;

		for (int i = 0; i < k; i++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			graph[u - 1].push_back(edge(v - 1, c, d));
		}

		dijstra();

		for (int i = 0; i <= m; i++)
			result = min(result, cache[n - 1][i]);

		if (result == INF)
			cout << "Poor KCM" << endl;
		else
			cout << result << endl;
	}

	return 0;
}