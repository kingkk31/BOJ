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

bool cmp(const pair<int, int> &left, const pair<int, int> &right)
{
	return left.first < right.first;
}

int main(void) 
{
	int n, m, i, j, k, num, cnt;
	scanf("%d %d", &n, &m);

	vector<pair<int, int> > vt(n);
	for (int a = 0; a < n; a++)
	{
		scanf("%d", &num);
		vt[a] = make_pair(num, a);
	}

	sort(vt.begin(), vt.end(), cmp);

	while (m--) 
	{
		scanf("%d %d %d", &i, &j, &k);
		cnt = 0;
		for (int a = 0; a < vt.size(); a++)
		{
			if (i - 1 <= vt[a].second && vt[a].second <= j - 1)
				cnt++;
			if (cnt == k)
			{
				printf("%d\n", vt[a]);
				break;
			}
		}
	}

	return 0;
}