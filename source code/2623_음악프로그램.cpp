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
vector<int> indegree;
vector<vector<int> > vt;
vector<int> ans;

void solve()
{
	priority_queue<int, vector<int>, greater<int> > qu;
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
			qu.push(i);

	while (!qu.empty())
	{
		int cur = qu.top();
		qu.pop();
		ans.push_back(cur + 1);

		for (int i = 0; i < vt[cur].size(); i++)
		{
			int next = vt[cur][i];
			indegree[next]--;

			if (indegree[next] == 0)
				qu.push(next);
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	indegree = vector<int>(n, 0);
	vt = vector<vector<int> >(n);

	for (int i = 0; i < m; i++)
	{
		int num;
		scanf("%d", &num);

		vector<int> temp(n);
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &temp[j]);
			temp[j]--;
			if (j == 0)
				continue;
			indegree[temp[j]]++;
			vt[temp[j - 1]].push_back(temp[j]);
		}
	}

	solve();
	if (ans.size() != n)
		printf("0\n");
	else
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);

	return 0;
}