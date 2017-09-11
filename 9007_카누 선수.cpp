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
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int k, n;
		int arr[4][1001];
		scanf("%d %d", &k, &n);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);

		vector<int> vt1, vt2;
		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++)
			{
				vt1.push_back(arr[0][i] + arr[1][j]);
				vt2.push_back(arr[2][i] + arr[3][j]);
			}

		sort(vt1.begin(), vt1.end());
		int weight = vt1[0] + vt2[0];
		
		for (int i = 0; i < vt2.size(); i++)
		{
			int lo = 0, hi = vt2.size() - 1, mid;
			while (lo <= hi)
			{
				mid = (lo + hi) / 2;

				if (vt1[mid] + vt2[i] == k)
				{
					weight = k;
					break;
				}
				else
				{
					if (abs(k - weight) > abs(k - (vt1[mid] + vt2[i])))
						weight = vt1[mid] + vt2[i];
					else if (abs(k - weight) == abs(k - (vt1[mid] + vt2[i])))
						weight = min(weight, vt1[mid] + vt2[i]);
					
					if (vt1[mid] + vt2[i] < k)
						lo = mid + 1;
					else
						hi = mid - 1;
				}
			}
		}
		
		printf("%d\n", weight);
	}

	return 0;
}