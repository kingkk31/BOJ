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
int n;
vector<vector<pp> > vt;

pp bfs(int start)
{
	vector<int> visited(n + 1, -1);
	queue<int> qu;

	int maxi = -1, pos = start;
	visited[start] = 0;
	qu.push(start);

	while (!qu.empty())
	{
		int cur = qu.front();
		qu.pop();
		
		if (maxi < visited[cur])
		{
			maxi = visited[cur];
			pos = cur;
		}

		for (int i = 0; i < vt[cur].size(); i++)
		{
			int next = vt[cur][i].first;
			int len = vt[cur][i].second;

			if (visited[next] == -1)
			{
				visited[next] = visited[cur] + len;
				qu.push(next);
			}
		}
	}

	return make_pair(pos, maxi);
}

int main(void)
{
	scanf("%d", &n);
	vt = vector<vector<pp> >(n + 1);

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d", &a);

		while (true)
		{
			scanf("%d", &b);
			if (b == -1)
				break;

			scanf("%d", &c);
			vt[a].push_back(make_pair(b, c));
		}
	}

	pp result = bfs(1);
	int pos = result.first, maxi = result.second;
	
	pp ans = bfs(pos);
	maxi = max(maxi, ans.second);

	printf("%d\n", maxi);
	
	return 0;
}