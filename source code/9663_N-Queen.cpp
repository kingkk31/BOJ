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

#define MAX 15
int n, cnt, col[MAX + 1], cross1[MAX * 2 + 1], cross2[MAX * 2 + 1];

void solve(int q)
{
	if (q > n)
	{
		cnt++;
		return;
	}

	for (int i = 1; i <= n; i++)
		if (!col[i] && !cross1[q + i] && !cross2[n + (q - i) + 1])
		{
			col[i] = cross1[q + i] = cross2[n + (q - i) + 1] = 1;
			solve(q + 1);
			col[i] = cross1[q + i] = cross2[n + (q - i) + 1] = 0;
		}
}

int main(void)
{
	cin >> n;
	solve(1);
	cout << cnt << endl;
}