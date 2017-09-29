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
		int n, maxi = 0;
		scanf("%d", &n);
		vector<int> vt(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &vt[i]);
		sort(vt.begin(), vt.end());

		int left, right;
		left = right = vt.back();
		vt.pop_back();

		while (vt.size() >= 2)
		{
			int a = vt.back();
			vt.pop_back();
			int b = vt.back();
			vt.pop_back();
			//b < a

			if (left < right)
			{
				if (left - b > maxi)
					maxi = left - b;
				left = b;

				if (right - a > maxi)
					maxi = right - a;
				right = a;
			}
			else
			{
				if (left - a > maxi)
					maxi = left - a;
				left = a;

				if (right - b > maxi)
					maxi = right - b;
				right = b;
			}
		}

		if (!vt.empty())
			maxi = max(maxi, max(left - vt[0], right - vt[0]));
		cout << maxi << endl;
	}

	return 0;
}