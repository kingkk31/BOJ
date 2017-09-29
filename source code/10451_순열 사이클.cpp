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

int n;
vector<int> vt1, vt2;
vector<bool> visited;

int solve(int pos)
{
	if (visited[pos])
		return 1;

	visited[pos] = true;
	return solve(vt2[pos]);
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, cnt = 0;
		scanf("%d", &n);

		vt1 = vector<int>(n + 1, 0);
		vt2 = vector<int>(n + 1, 0);
		visited = vector<bool>(n + 1, false);

		for (int i = 1; i <= n; i++)
		{
			vt1[i] = i;
			scanf("%d", &vt2[i]);
		}

		for (int i = 1; i <= n; i++)
			if (!visited[i])
				cnt += solve(i);
		
		cout << cnt << endl;
	}

	return 0;
}