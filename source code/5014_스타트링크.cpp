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

#define INF 987654321
int f, s, g, u, d;
vector<int> cache;

bool isRange(int pos)
{
	if (0 < pos && pos <= f)
		return true;
	return false;
}

void bfs(int start)
{
	queue<int> qu;
	qu.push(start);
	cache[s] = 0;

	while (!qu.empty())
	{
		int pos = qu.front();
		qu.pop();

		int next = pos + u;
		if (isRange(next) && cache[next] > cache[pos] + 1)
		{
			cache[next] = cache[pos] + 1;
			qu.push(next);
		}

		next = pos - d;
		if (isRange(next) && cache[next] > cache[pos] + 1)
		{
			cache[next] = cache[pos] + 1;
			qu.push(next);
		}
	}
}

int main(void)
{
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	cache = vector<int>(1000001, INF);
	bfs(s);

	if (cache[g] != INF)
		printf("%d\n", cache[g]);
	else
		printf("use the stairs\n");

	return 0;
}