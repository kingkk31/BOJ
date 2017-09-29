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

vector<vector<int> > vt;
int n, m;

int BFS(int start)
{
	vector<bool> visited(n + 1, false);
	queue<int> qu;
	qu.push(start);
	visited[start] = true;
	int cnt = 0;

	while (!qu.empty())
	{
		int current = qu.front();
		qu.pop();
		cnt++;

		for (int i = 0; i < vt[current].size(); i++)
		{
			int next = vt[current][i];
			if (!visited[next])
			{
				visited[next] = true;
				qu.push(next);
			}
		}
	}

	return cnt;
}

int main(void)
{
	cin >> n >> m;
	vt = vector<vector<int> >(n + 1);
	vector<int> computer(n+1, 0);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vt[b].push_back(a);
	}

	int maxi = 0;
	for (int i = 1; i <= n; i++)
	{
		computer[i] = BFS(i);
		maxi = max(maxi, computer[i]);
	}

	for (int i = 1; i <= n; i++)
		if (computer[i] == maxi)
			printf("%d ", i);

	return 0;
}