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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		vector<vector<int> > vt(100001);

		for (int i = 0; i < 100001; i++)
			vt[i].clear();

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			vt[x].push_back(y);
		}

		vector<pair<int, int> > pa;
		int tempy = 0;
		
		for (int i = 0; i < 100001;i++)
		{
			if (vt[i].empty())
				continue;

			sort(vt[i].begin(), vt[i].end());

			if (tempy > vt[i][0])
			{
				for (int j = vt[i].size() - 1; j >= 0; j--)
					pa.push_back(make_pair(i, vt[i][j]));
				tempy = vt[i][0];
			}
			else
			{
				for (int j = 0; j < vt[i].size(); j++)
					pa.push_back(make_pair(i, vt[i][j]));
				tempy = vt[i].back();
			}
		}

		int k;
		scanf("%d", &k);

		for (int i = 0; i < k; i++)
		{
			int num;
			scanf("%d", &num);
			num--;
			printf("%d %d\n", pa[num].first, pa[num].second);
		}
	}

	return 0;
}
