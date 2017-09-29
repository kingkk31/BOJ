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

int n, d, k, c, maxi;
vector<int> vt;
int cache[30001];

int main(void)
{
	scanf("%d %d %d %d", &n, &d, &k, &c);
	vt = vector<int>(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	maxi = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		memset(cache, -1, sizeof(cache));
		for (int j = i; j < i + k; j++)
		{
			int num = vt[j%n];
			if (cache[num] != -1)
				continue;
			cache[num] = 1;
			cnt++;
		}

		if (cache[c] == -1)
			cnt++;
		maxi = max(maxi, cnt);
	}

	cout << maxi << endl;

	return 0;
}