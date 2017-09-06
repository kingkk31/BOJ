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

vector<pair<int, int> > vt[801];
int INF = 987654321;
int n;

int BFS(int from, int to)
{
	vector<int> total(n + 1, INF);
	priority_queue<pair<int, int> > qu;

	total[from] = 0;
	qu.push(make_pair(0, from));

	while (!qu.empty())
	{
		int cost = -qu.top().first;
		int here = qu.top().second;
		qu.pop();

		if (total[here] < cost)
			continue;

		for (int j = 0; j < vt[here].size(); j++)
		{
			int next = vt[here][j].first;
			int nextCost = cost + vt[here][j].second;

			if (total[next] > nextCost)
			{
				total[next] = nextCost;
				qu.push(make_pair(-nextCost, next));
			}
		}
	}

	return total[to];
}

int main(void)
{
	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int s, f, p;
		cin >> s >> f >> p;

		vt[s].push_back(make_pair(f, p));
		vt[f].push_back(make_pair(s, p));
	}

	int must1, must2;
	cin >> must1 >> must2;
	
	int cnt1=0, cnt2=0;
	for (int i = 0; i < 1; i++)
	{
		int a1 = BFS(1, must1);
		if (a1 == INF)
		{
			cnt1 = INF;
			break;
		}
		cnt1 += a1;

		int a2 = BFS(must1, must2);
		if (a2 == INF)
		{
			cnt1 = INF;
			break;
		}

		cnt1 += a2;

		int a3 = BFS(must2, n);
		if (a3 == INF)
		{
			cnt1 = INF;
			break;
		}

		cnt1 += a3;
	}

	for (int i = 0; i < 1; i++)
	{
		int b1 = BFS(1, must2);
		if (b1 == INF)
		{
			cnt2 = INF;
			break;
		}

		cnt2 += b1;

		int b2 = BFS(must2, must1);
		if (b2 == INF)
		{
			cnt2 = INF;
			break;
		}

		cnt2 += b2;

		int b3 = BFS(must1, n);
		if (b3 == INF)
		{
			cnt2 = INF;
			break;
		}

		cnt2 += b3;
	}
	
	if (cnt1 == INF && cnt2 == INF)
		cout << -1 << endl;
	else if (cnt1 == INF)
		cout << cnt2 << endl;
	else if (cnt2 == INF)
		cout << cnt1 << endl;
	else
		cout << min(cnt1, cnt2) << endl;

	return 0;
}