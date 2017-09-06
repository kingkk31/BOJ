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
#pragma warning(disable:4996)
using namespace std;

const long long INF = 987654321;
const long long MAX = 10000;
int V;
vector<pair<int, long long> > adj[MAX];

long long prim()
{
	vector<bool> added(V, false);
	vector<long long> minWeight(V, INF), parent(V, -1);
	
	long long ret = 0;
	minWeight[0] = parent[0] = 0;

	for (int iter = 0; iter < V; ++iter)
	{
		int u = -1;
		
		for (int v = 0; v < V; ++v)
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;
		
		ret += minWeight[u];
		added[u] = true;

		for (int i = 0; i < adj[u].size(); ++i)
		{
			int v = adj[u][i].first, weight = adj[u][i].second;

			if (!added[v] && minWeight[v] > weight)
			{
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}

	return ret;
}

int main(void)
{
	int e;
	cin >> V >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b;
		long long c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a - 1].push_back(make_pair(b - 1, c));
		adj[b - 1].push_back(make_pair(a - 1, c));
	}

	cout << prim() << endl;

	return 0;
}