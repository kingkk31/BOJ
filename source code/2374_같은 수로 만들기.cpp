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

int n, maxi;
vector<int> vt;

int search_min()
{
	auto result = minmax_element(vt.begin(), vt.end());
	return result.first - vt.begin();
}

int main(void)
{
	maxi = 0;
	unsigned long long cnt = 0;
	scanf("%d", &n);
	vt = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vt[i]);
		maxi = max(maxi, vt[i]);
	}

	while (true)
	{
		int le, ri;
		le = ri = search_min();
		if (vt[le] == maxi)
			break;

		while (true)
		{
			if (le - 1 < 0 && ri + 1 >= n)
				break;
			else if (le - 1 < 0)
			{
				if (vt[ri + 1] < vt[ri])
					break;
				else
				{
					cnt += vt[ri + 1] - vt[ri];
					for (int i = le; i <= ri; i++)
						vt[i] = vt[ri + 1];
					ri++;
				}
			}
			else if (ri + 1 >= n)
			{
				if (vt[le - 1] < vt[le])
					break;
				else
				{
					cnt += vt[le - 1] - vt[le];
					for (int i = le; i <= ri; i++)
						vt[i] = vt[le - 1];
					le--;
				}
			}
			else
			{
				if (vt[le - 1] < vt[le] || vt[ri + 1] < vt[ri])
					break;
				else
				{
					if (vt[le - 1] < vt[ri + 1])
					{
						cnt += vt[le - 1] - vt[le];
						for (int i = le; i <= ri; i++)
							vt[i] = vt[le - 1];
						le--;
					}
					else 
					{
						cnt += vt[ri + 1] - vt[ri];
						for (int i = le; i <= ri; i++)
							vt[i] = vt[ri + 1];
						ri++;
					}
				}
			}
		}
	}
	cout << cnt << endl;

	return 0;
}