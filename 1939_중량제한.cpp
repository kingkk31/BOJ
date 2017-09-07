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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321
#define pp pair<int, int>
#define mk make_pair
int n, m, s, e;
vector<pp> vt[100001];
queue<int> qu;
int visited[100001];

bool bfs(int w)
{
	memset(visited, -1, sizeof(visited));
	visited[s] = 1;
	while (!qu.empty())
		qu.pop();
	qu.push(s);

	while (!qu.empty())
	{
		int cur = qu.front();
		qu.pop();

		if (cur == e)
			return true;

		for (int i = 0; i < vt[cur].size(); i++)
		{
			int next = vt[cur][i].first, weight = vt[cur][i].second;
			if (visited[next] == -1 && w <= weight)
			{
				qu.push(next);
				visited[next] = 1;
			}
		}
	}
	return false;
}

int binarySearch(int r)
{
	int left = 0, right = r, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (!bfs(mid))
			right = mid - 1;
		else
		left = mid + 1;
	}
	return right;
}

int main(void)
{
	int a, b, c, maxi = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		vt[a - 1].push_back(mk(b - 1, c));
		vt[b - 1].push_back(mk(a - 1, c));
		maxi = max(maxi, c);
	}

	scanf("%d %d", &s, &e);
	s--; e--;

	cout << binarySearch(maxi) << endl;

	return 0;
}