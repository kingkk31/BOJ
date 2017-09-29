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

#define LL long long
#define INF 987654321
#define mk make_pair
int n, m, k;
LL cache[10001][21];
vector<pair<int, int> > vt[10001];

void daijkstra()
{
	priority_queue<pair<LL, pair<int, int> > > qu;
	qu.push(mk(0, mk(1, k)));
	cache[1][k] = 0;

	while (!qu.empty())
	{
		int current = qu.top().second.first;
		int cnt = qu.top().second.second;
		LL w = qu.top().first * -1;
		qu.pop();

		if (cache[current][cnt] <= w) 
		{
			for (int i = 0; i < vt[current].size(); i++) 
			{
				int next = vt[current][i].first;
				LL cost = vt[current][i].second + w;

				if (cnt > 0 && w < cache[next][cnt - 1])
				{
					cache[next][cnt - 1] = w;
					qu.push(mk(w * -1, mk(next, cnt - 1)));
				}

				if (cost < cache[next][cnt]) 
				{
					cache[next][cnt] = cost;
					qu.push(mk(cost * -1, mk(next, cnt)));
				}
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < 10001; i++)
		for (int j = 0; j < 21; j++)
			cache[i][j] = INF;

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		vt[a].push_back(mk(b, t));
		vt[b].push_back(mk(a, t));
	}
	
	daijkstra();
	LL result = INF;
	for (int i = 0; i <= k; i++)
		result = min(result, cache[n][i]);
	cout << result << endl;

	return 0;
}