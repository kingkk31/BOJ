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

int BFS(int start, vector<vector<int> > &vt, vector<bool> &visited)
{
	int cnt = 0;
	visited[start] = true;
	queue<int> qu;
	qu.push(start);

	while (!qu.empty())
	{
		int current = qu.front();
		qu.pop();

		for (int i = 0; i < vt[current].size(); i++)
		{
			int next = vt[current][i];

			if (!visited[next])
			{
				visited[next] = true;
				cnt++;
				qu.push(next);
			}
		}
	}

	return cnt;
}

int main(void)
{
	int n,m;
	cin >> n >> m;

	vector<vector<int> > vt(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vt[a - 1].push_back(b - 1);
		vt[b - 1].push_back(a - 1);
	}

	vector<bool> visited(n, false);

	cout<< BFS(0, vt, visited) << endl;
	
	return 0;
}