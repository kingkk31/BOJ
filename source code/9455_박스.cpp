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
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n;
		cin >> m >> n;

		vector<vector<int> > vt(m, vector<int>(n));
		vector<vector<int> > box(n);

		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> vt[j][k];
				
				if (vt[j][k] == 1)
					box[k].push_back(m-1-j);
			}
		}
	
		int cnt = 0;

		for (int j = 0; j < box.size(); j++)
		{
			int down = 0;
			for (int k = box[j].size() - 1; k >= 0; k--)
			{
				cnt += (box[j][k] - down);
				down++;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}
