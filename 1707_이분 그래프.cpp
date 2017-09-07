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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

int n, v, e;
vector<vector<int> > vt;

bool bfs(vector<char> &color, int start)
{
	queue<int> qu;
	color[start] = 'r';
	qu.push(start);

	while (!qu.empty())
	{
		int cur = qu.front();
		qu.pop();

		for (int i = 0; i < vt[cur].size(); i++)
		{
			int next = vt[cur][i];
			if (color[next] == 'b')
			{
				color[next] = color[cur] == 'r' ? 'g' : 'r';
				qu.push(next);
			}
			else
			{
				if (color[cur] == color[next])
					return false;
				else
					continue;
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
		scanf("%d %d", &v, &e);
		vt = vector<vector<int> >(v+1);

		for (int i = 0; i < e; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			vt[a].push_back(b);
			vt[b].push_back(a);
		}

		vector<char> color(v + 1, 'b');
		bool flag = false;
		for (int i = 1; i <= v; i++)
		{
			if (color[i] == 'b')
			{
				bool ans = bfs(color, i);
				if (!ans)
					flag = true;
			}
		}

		cout << (!flag ? "YES" : "NO") << endl;
	}

	return 0;
}