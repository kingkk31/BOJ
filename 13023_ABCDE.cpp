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

vector<vector<int> > vt;
int n, m;
int visited[2001];
bool flag;

void dfs(int pos, int cnt)
{
	if (cnt == 5)
	{
		flag = true;
		return;
	}

	visited[pos] = 1;
	for (int i = 0; i < vt[pos].size(); i++)
	{
		int next = vt[pos][i];
		if (visited[next] == -1)
			dfs(next, cnt + 1);
		
		if (flag)
			return;
	}
	visited[pos] = -1;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	vt = vector<vector<int> >(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	flag = false;
	for (int i = 0; i < n; i++)
	{
		memset(visited, -1, sizeof(visited));
		dfs(i, 1);

		if (flag)
			break;
	}
	
	cout << (flag ? 1 : 0) << endl;

	return 0;
}