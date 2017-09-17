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

int n, m;
vector<int> vt;
vector<int> sum;

void partialSum()
{
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + vt[i];
}

int main(void)
{
	cin >> n;
	vt = vector<int>(n + 1);
	sum = vector<int>(n + 1);
	vt[0] = 0;

	for (int i = 1; i <= n; i++)
		scanf("%d", &vt[i]);
	partialSum();

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}

	return 0;
}