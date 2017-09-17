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
		int n, m, x = 0, y = 0, cnt = 0;
		scanf("%d %d", &n, &m);
		for (int i = m - 1; i >= 0; i--)
		{
			int num;
			scanf("%d", &num);
			x += num * pow(10, i);
		}
		for (int i = m - 1; i >= 0; i--)
		{
			int num;
			scanf("%d", &num);
			y += num * pow(10, i);
		}

		vector<int> vt(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &vt[i]);

		for (int i = 0; i < n; i++)
		{
			int z = 0;
			for (int j = 0; j < m; j++)
				z += vt[(i + j) % n] * pow(10, m - j - 1);
			
			if (x <= z && z <= y)
				cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}