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

int n;
const int INF = 987654321;
vector<vector<int> > dist;

int shortestPath(vector<int>& path, vector<bool>& visited, int currentLength)
{
	if (path.size() == n)
		return currentLength + dist[path.back()][path.front()];

	int ret = INF;

	for (int next = 0; next < n; ++next)
	{
		if (visited[next])
			continue;

		int here = path.back();
		if (dist[here][next] == 0)
			continue;

		path.push_back(next);
		visited[next] = true;

		int cand = shortestPath(path, visited, currentLength + dist[here][next]);

		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}

	return ret;
}

int main(void)
{
	cin >> n;

	dist = vector<vector<int> >(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];

	int total = INF;

	vector<int> path;
	vector<bool> visited(n, false);
	path.push_back(0);
	visited[0] = true;
	total = min(total, shortestPath(path, visited, 0));

	if (total == INF)
		cout << 0 << endl;
	else
		cout << total << endl;

	return 0;
}