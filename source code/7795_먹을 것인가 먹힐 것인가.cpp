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
	scanf("%d", &t);
	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		vector<int> vt1(a), vt2(b);
		for (int i = 0; i < a; i++)
			scanf("%d", &vt1[i]);
		for (int i = 0; i < b; i++)
			scanf("%d", &vt2[i]);

		sort(vt1.begin(), vt1.end());
		sort(vt2.begin(), vt2.end());

		int cnt = 0;
		for (int i = 0; i < a; i++)
		{
			vector<int>::iterator itr = lower_bound(vt2.begin(), vt2.end(), vt1[i]);
			cnt += (itr - vt2.begin());
		}

		cout << cnt << endl;
	}

	return 0;
}