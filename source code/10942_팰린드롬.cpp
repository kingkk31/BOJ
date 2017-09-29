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

int cache[5001][5001];

int main(void)
{
	int n;
	scanf("%d", &n);

	vector<int> str(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &str[i]);

	memset(cache, -1, sizeof(cache));

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == b)
		{
			printf("1\n");
			continue;
		}

		int &ret = cache[a - 1][b - 1];

		if (ret != -1)
		{
			printf("%d\n", ret);
			continue;
		}

		vector<int> temp, temp1, temp2;
		temp.assign(str.begin() + (a - 1), str.begin() + b);
		temp1.assign(temp.begin(), temp.begin() + (temp.size() / 2) + 1);
		reverse(temp.begin(), temp.end());
		temp2.assign(temp.begin(), temp.begin() + (temp.size() / 2) + 1);

		bool ch = false;

		for (int i = 0; i < temp1.size(); i++)
		{
			if (temp1[i] != temp2[i])
			{
				ch = true;
				break;
			}
		}

		if (ch)
			ret = 0;
		else
			ret = 1;

		printf("%d\n", ret);
	}

	return 0;
}
