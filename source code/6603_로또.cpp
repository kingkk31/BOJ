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

void solve(vector<int> vt, vector<int> &num, int cache)
{
	if (num.size() == 6)
	{
		for (int i = 0; i < num.size(); i++)
			printf("%d ", num[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < vt.size(); i++)
	{
		if (!(cache & (1 << i)) && (num.empty() || num.back() < vt[i]))
		{
			num.push_back(vt[i]);
			cache |= (1 << i);
			solve(vt, num, cache);
			cache &= ~(1 << i);
			num.pop_back();
		}
	}
}

int main(void)
{
	int k, cache;
	vector<int> vt, num;

	while (true)
	{
		scanf("%d", &k);
		if (k == 0)
			break;

		vt.resize(k);
		cache = (1 << k);
		for (int i = 0; i < k; i++)
			scanf("%d", &vt[i]);
		
		solve(vt, num, cache);
		vt.clear();
		num.clear();
		cout << endl;
	}

	return 0;
}