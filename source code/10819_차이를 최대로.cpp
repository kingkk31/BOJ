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
int n, ans, arr[8], visited[8];

void solve(int cnt, int sum, int pre)
{
	if (cnt >= n)
	{
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			solve(cnt + 1, sum + abs(arr[i] - pre), arr[i]);
			visited[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	memset(visited, 0, sizeof(visited));
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		visited[i] = 1;
		solve(1, 0, arr[i]);
		visited[i] = 0;
	}
	cout << ans << endl;

	return 0;
}