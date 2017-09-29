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

int main(void)
{
	int n, q, l, i;
	scanf("%d %d", &n, &q);

	vector<bool> vt(n + 1, false);
	for (int j = 0; j < q; j++)
	{
		scanf("%d %d", &l, &i);
		int pos = l;
		while (pos <= n)
		{
			vt[pos] = true;
			pos += i;
		}
	}

	int cnt = 0;
	for (int j = 1; j <= n; j++)
		if (!vt[j])
			cnt++;
	printf("%d\n", cnt);

	return 0;
}