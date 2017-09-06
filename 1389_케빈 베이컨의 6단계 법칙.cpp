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
#pragma warning(disable:4996)
using namespace std;

int n, m;

int bfs(vector<vector<int> > vt, int start)
{
	int total = 0;

	vector<int> cnt(n, -1);
	queue<int> qu;
	qu.push(start);
	cnt[start] = 0;

	while (!qu.empty())
	{
		int temp = qu.front();
		qu.pop();
		total += cnt[temp];
		
		for (int i = 0; i < vt[temp].size(); i++)
		{
			if (cnt[vt[temp][i]] == -1)
			{
				cnt[vt[temp][i]] = cnt[temp] + 1;
				qu.push(vt[temp][i]);
			}
		}
	}

	return total;
}

int main(void)
{
	cin >> n >> m;

	vector<vector<int> > vt(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		vt[a - 1].push_back(b - 1);
		vt[b - 1].push_back(a - 1);
	}

	int mini = bfs(vt, 0);
	int kevin = 0;

	for (int i = 1; i < n; i++)
	{
		int temp = bfs(vt, i);
		if(mini > temp)
		{
			mini = temp;
			kevin = i;
		}
	}
	cout << kevin+1 << endl;

	return 0;
}