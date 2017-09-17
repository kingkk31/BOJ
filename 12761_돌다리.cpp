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
int n, m, a, b;

bool isRange(int pos)
{
	if (0 <= pos && pos <= 100000)
		return true;
	return false;
}

void BFS(int pos, vector<int> &cache)
{
	queue<int> qu;
	qu.push(pos);
	cache[pos] = 0;

	while (!qu.empty())
	{
		int pos = qu.front();
		qu.pop();

		for (int i = 0; i < 8; i++)
		{
			int next;
			switch (i)
			{
			case 0: next = pos + 1; break;
			case 1: next = pos - 1; break;
			case 2: next = pos + a; break;
			case 3: next = pos - a; break;
			case 4: next = pos + b; break;
			case 5: next = pos - b; break;
			case 6: next = pos * a; break;
			case 7: next = pos * b; break;
			}

			if (isRange(next) && cache[next] > cache[pos] + 1)
			{
				cache[next] = cache[pos] + 1;
				qu.push(next);
			}
		}
	}
}

int main(void)
{
	cin >> a >> b >> n >> m;
	vector<int> cache(100001, INF);
	BFS(n, cache);
	cout << cache[m] << endl;
	return 0;
}