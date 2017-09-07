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
#pragma warning(disable:4996)
using namespace std;

vector<pair<int, int> > vt[1001];
priority_queue<pair<int, int> > qu;
int INF = 987654321;

void BFS(int from, vector<int> &totalMoney)
{
	totalMoney[from] = 0;
	qu.push(make_pair(0,from));

	while (!qu.empty())
	{
		int cost = -qu.top().first;
		int here = qu.top().second;
		qu.pop();
		
		if (totalMoney[here] < cost)
			continue;

		for (int j = 0; j < vt[here].size(); j++)
		{
			int next = vt[here][j].first;
			int nextCost = cost + vt[here][j].second;
			
			if (totalMoney[next] > nextCost)
			{
				totalMoney[next] = nextCost;
				qu.push(make_pair(-nextCost, next));
			}
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

	int m;
	cin >> m;

	vector<int> totalMoney(n + 1, INF);
	
	for (int i = 0; i < m; i++)
	{
		int s, f, p;
		cin >> s >> f >> p;
		
		vt[s].push_back(make_pair(f,p));
	
	}

	int from, to;
	cin >> from >> to;

	BFS(from, totalMoney);

	cout << totalMoney[to] << endl;

	return 0;
}