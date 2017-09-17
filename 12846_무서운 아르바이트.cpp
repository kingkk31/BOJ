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
	int n;
	scanf("%d", &n);
	vector<int> vt(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);
	
	long long maxi = 0LL;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		if (i != 0)
		{
			int l = i - 1;
			while (l >= 0)
			{
				if (vt[l] < vt[i])
					break;
				l--;
			}
			cnt += (i - l - 1);
		}
		if (i != n-1)
		{
			int r = i + 1;
			while (r < n)
			{
				if (vt[r] < vt[i])
					break;
				r++;
			}
			cnt += (r - i - 1);
		}
		maxi = max(maxi, (long long)(cnt * vt[i]));
	}
	printf("%lld\n", maxi);

	return 0;
}