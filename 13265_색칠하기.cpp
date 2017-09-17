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

int n, m;
vector<vector<int> > vt;

bool solve(int s, vector<int> &visited)
{
	queue<int> qu;
	qu.push(s);
	visited[s] = 1;

	while (!qu.empty())
	{
		int cur = qu.front();
		qu.pop();

		for (int i = 0; i < vt[cur].size(); i++)
		{
			int next = vt[cur][i];
			
			if (visited[cur] == visited[next])
				return false;
			else if (visited[next] == 0)
			{
				visited[next] = visited[cur] == 1 ? 2 : 1;
				qu.push(next);
			}
		}
	}

	return true;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		vt = vector<vector<int> >(n);

		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			vt[a - 1].push_back(b - 1);
			vt[b - 1].push_back(a - 1);
		}

		bool flag = true;
		vector<int> visited(n, 0);
		int c = 0;
		while(c < n)
		{
			if (visited[c] == 0)
			{
				flag = solve(c, visited);
				if (!flag)
					break;
				
				c = 0;
				continue;
			}
			c++;
		}

		if (!flag)
			cout << "impossible" << endl;
		else
			cout << "possible" << endl;
	}

	return 0;
}