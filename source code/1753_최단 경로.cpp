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

vector<pair<int, int> > vt[20001];
priority_queue<pair<int, int> > qu;
int INF = 987654321;

void BFS(int from, vector<int> &total)
{
	total[from] = 0;
	qu.push(make_pair(0,from));

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
}

int main(void)
{
	int n,m;
	cin >> n >> m;

	int start;
	cin >> start;

	vector<int> total(n + 1, INF);
	
	for (int i = 0; i < m; i++)
	{
		int s, f, p;
		cin >> s >> f >> p;
		
		vt[s].push_back(make_pair(f,p));
	}

	BFS(start, total);

	for (int i = 1; i <= n; i++)
		if(total[i] == 987654321)
			cout << "INF" << endl;
		else
			cout << total[i] << endl;

	return 0;
}