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
int n, m, cache[501];
vector<pp> vt[501];

void bellmanFord(int start)
{
	for (int i = 0; i < 501; i++)
		cache[i] = INF;

	cache[start] = 0;
	bool flag;

	for (int t = 0; t < n; t++)
	{
		flag = false;

		for (int cur = 0; cur < n; cur++)
		{
			for (int i = 0; i < vt[cur].size(); i++)
			{
				int next = vt[cur][i].first;
				int cost = vt[cur][i].second;

				if (cache[next] > cache[cur] + cost)
				{
					cache[next] = cache[cur] + cost;
					flag = true;
				}
			}
		}

		if (!flag)
			break;
	}

	if (flag)
	{
		cout << "-1" << endl;
		return;
	}

	for (int i = 1; i < n; i++)
		cout << (cache[i] == INF ? -1 : cache[i]) << endl;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		vt[a - 1].push_back(mk(b - 1, c));
	}

	bellmanFord(0);
	
	return 0;
}