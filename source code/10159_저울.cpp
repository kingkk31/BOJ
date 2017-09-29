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

vector<vector<int> > vt;
vector<vector<bool> > visited;
int n, m;

void DFS(int start, int node)
{
	visited[node][start] = true;
	visited[start][node] = true;

	for (int i = 0; i < vt[node].size(); i++)
	{
		int next = vt[node][i];

		if (visited[start][next] == false)
			DFS(start, next);
	}
}

int main(void)
{
	cin >> n;
	cin >> m;

	vt = vector<vector<int> >(n + 1);
	visited = vector<vector<bool> >(n + 1, vector<bool>(n + 1, false));

	for (int i = 0; i < m; i++)
	{
		int s, f;
		cin >> s >> f;
		
		vt[s].push_back(f);
	}

	for (int k = 1; k <= n; k++)
		DFS(k, k);
	
	for (int i = 1; i <= n;i++)
	{
		int num = 0;
		
		for (int j = 1; j <= n; j++)
			if (visited[i][j] == false)
				num++;

		cout << num << endl;
	}

	return 0;
}