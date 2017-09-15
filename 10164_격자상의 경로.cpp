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

int cache[16][16];

bool isRange(int y, int x, int sy, int sx, int fy, int fx)
{
	if (sy <= y && y <= fy && sx <= x && x <= fx)
		return true;
	return false;
}

int solve(int py, int px, int sy, int sx, int fy, int fx)
{
	if (py == fy && px == fx)
		return 1;

	int &ret = cache[py][px];
	if (ret != -1)
		return ret;
	ret = 0;

	if (isRange(py + 1, px, sy, sx, fy, fx))
		ret += solve(py + 1, px, sy, sx, fy, fx);

	if (isRange(py, px + 1, sy, sx, fy, fx))
		ret += solve(py, px + 1, sy, sx, fy, fx);

	return ret;
}

int main(void)
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	memset(cache, -1, sizeof(cache));

	int sy = 0, sx = 0, fy = n - 1, fx = m - 1, my, mx;
	
	if (k != 0)
	{
		int cnt = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (cnt == k)
				{
					my = i;
					mx = j;
				}
				cnt++;
			}
		
		int r1 = solve(sy, sx, sy, sx, my, mx);
		memset(cache, -1, sizeof(cache));
		int r2 = solve(my, mx, my, mx, fy, fx);
		cout << r1*r2 << endl;
	}
	else
		cout << solve(sy, sx, sy, sx, fy, fx) << endl;

	return 0;
}