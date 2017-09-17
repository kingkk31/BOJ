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

int dfs(vector<vector<int> > &vt, vector<bool> &visited, int num)
{
	visited[num] = true;
	int temp;
	
	for (int i = 0; i < vt[num].size(); i++)
	{
		if (visited[vt[num][i]] == false)
			temp = dfs(vt, visited, vt[num][i]);
	}

	return 1;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<vector<int> > vt(n);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		vt[s - 1].push_back(e - 1);
		vt[e - 1].push_back(s - 1);
	}

	vector<bool> visited(n, false);
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
			cnt += dfs(vt, visited, i);
	}

	cout << cnt << endl;

	return 0;
}