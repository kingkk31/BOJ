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

#define INF 987654321
#define pp pair<int, int>
int n;
vector<vector<pp> > vt;

int BFS(int start)
{
	int maxi = -1;
	vector<int> visited(n, -1);
	visited[start] = 0;
	queue<int> qu;
	qu.push(start);

	while (!qu.empty())
	{
		int current = qu.front();
		qu.pop();
		maxi = max(maxi, visited[current]);

		for (int i = 0; i < vt[current].size(); i++)
		{
			int next = vt[current][i].first;
			int weight = vt[current][i].second;
			
			if (visited[next] == -1)
			{
				visited[next] = weight + visited[current];
				qu.push(next);
			}
		}
	}

	return maxi;
}

int main(void)
{
	cin >> n;
	vt = vector<vector<pp> >(n);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		vt[a - 1].push_back(make_pair(b - 1, c));
		vt[b - 1].push_back(make_pair(a - 1, c));
	}

	int maxi = -1;
	for (int i = 0; i < n; i++)
		maxi = max(maxi, BFS(i));

	cout << maxi << endl;
	
	return 0;
}