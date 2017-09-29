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

#define pp pair<int, int>
#define mk make_pair
#define INF 987654321
int n, m;
vector<vector<pp> > vt;

int prim(vector<pp> &selected)
{
	selected.clear();
	
	vector<bool> added(n, false);
	vector<int> minWeight(n, INF), parent(n, -1);
	int ret = 0;

	minWeight[0] = parent[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int next = -1;
		
		for (int j = 0; j < n; j++)
			if (!added[j] && (next == -1 || minWeight[next] > minWeight[j]))
				next = j;

		if (parent[next] != next)
			selected.push_back(mk(parent[next], next));

		ret += minWeight[next];
		added[next] = true;

		for (int j = 0; j < vt[next].size(); j++)
		{
			int v = vt[next][j].first, weight = vt[next][j].second;
			if (!added[v] && minWeight[v] > weight)
			{
				parent[v] = next;
				minWeight[v] = weight;
			}
		}
	}

	return ret;
}

int main(void)
{
	cin >> n >> m;
	vector<pp> selected;
	vt.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vt[a - 1].push_back(mk(b - 1, c));
		vt[b - 1].push_back(mk(a - 1, c));
	}

	cout << prim(selected) << endl;

	return 0;
}