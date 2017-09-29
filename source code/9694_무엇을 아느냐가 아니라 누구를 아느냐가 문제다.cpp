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
#define pp pair<int,int>
#define mk make_pair
int n, m, mini;
vector<int> result;
vector<vector<pp> > vt;

void solve(int pos, vector<int> &line, int cnt, vector<bool> &visited)
{
	if (pos == m - 1)
	{
		if (mini > cnt)
		{
			mini = cnt;
			result = line;
		}
		return;
	}

	for (int i = 0; i < vt[pos].size(); i++)
	{
		int next = vt[pos][i].first;
		int weight = vt[pos][i].second;
		if (mini <= cnt + weight)
			continue;

		if (!visited[next])
		{
			visited[next] = true;
			line.push_back(next);
			solve(next, line, cnt + weight, visited);
			visited[next] = false;
			line.pop_back();
		}
	}
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		scanf("%d %d", &n, &m);
		mini = INF;
		vt = vector<vector<pp> >(m);
		result.clear();

		while (n--)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			vt[a].push_back(mk(b, c));
			vt[b].push_back(mk(a, c));
		}

		vector<bool> visited(m, false);
		vector<int> line;
		line.push_back(0);
		visited[0] = true;

		solve(0, line, 0, visited);
		cout << "Case #" << i << ": ";
		if (mini == INF)
			cout << -1 << endl;
		else 
		{
			for (int j = 0; j < result.size(); j++)
				cout << result[j] << " ";
			cout << endl;
		}
	}

	return 0;
}