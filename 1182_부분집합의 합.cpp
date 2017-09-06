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

int n, m, cnt;
vector<int> vt;

void solve(int pos, int sum)
{
	if (pos >= n)
		return;

	if (sum + vt[pos] == m)
		cnt++;
	
	solve(pos + 1, sum + vt[pos]);
	solve(pos + 1, sum);
}

int main(void)
{
	scanf("%d %d", &n, &m);
	vt = vector<int>(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	solve(0, 0);
	printf("%d\n", cnt);

	return 0;
}
