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

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, cnt = 0;
		cin >> n;

		vector<int> vt(n), temp(n);
		bool check = false;
	
		scanf("%d", &vt[0]);
		if (vt[0] % 2 != 0)
			vt[0]++;
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &vt[i]);
			if (vt[i] % 2 != 0)
				vt[i]++;

			if (vt[0] != vt[i])
				check = true;
		}

		if (!check)
		{
			cout << 0 << endl;
			continue;
		}

		while (1)
		{
			check = false;

			for (int i = 0; i < n; i++)
			{
				int s = (i - 1) < 0 ? n - 1 : i - 1;
				temp[i] = vt[i] + vt[s];
			}

			vt[0] = temp[0] / 2;
			if (vt[0] % 2 != 0)
				vt[0]++;

			for (int i = 1; i < n; i++)
			{
				vt[i] = temp[i]/2;
				if (vt[i] % 2 != 0)
					vt[i]++;
				
				if (vt[0] != vt[i])
					check = true;
			}

			cnt++;
			if (!check)
				break;
		}

		cout << cnt << endl;
	}

	return 0;
}