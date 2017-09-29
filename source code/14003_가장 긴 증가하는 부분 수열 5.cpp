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

int vt[1000003], cache[1000003], pre[1000003];

int main(void)
{
	int n;
	scanf("%d", &n);

	int top = 0;

	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	for (int i = 0; i < n; i++)
	{
		if (!top) 
			cache[top++] = i;
		else if (vt[cache[top - 1]] < vt[i]) 
		{
			pre[i] = cache[top - 1];
			cache[top++] = i;
		}
		else 
		{
			int l = 0, r = top - 1, m;
			while (l <= r) 
			{
				m = (l + r) / 2;
				if (vt[cache[m]] >= vt[i])
					r = m - 1;
				else 
					l = m + 1;
			}

			if (vt[cache[m]] < vt[i])
				m++;
			cache[m] = i;

			if (m != 0)
				pre[i] = cache[m - 1];
			top = max(m + 1, top);
		}
	}

	printf("%d\n", top);
	vector<int> path(top);
	int j = cache[top - 1];
	for (int i = path.size() - 1; i >= 0; i--)
	{
		path[i] = vt[j];
		j = pre[j];
	}

	for (int i = 0; i < path.size();i++)
		printf("%d ", path[i]);

	return 0;
}