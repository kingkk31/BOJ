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

void partialSum(vector<int> &vt, vector<int> &cache)
{
	cache[0] = vt[0];
	for (int i = 1; i < vt.size(); i++)
		cache[i] = cache[i - 1] + vt[i];
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> vt(n), cache(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	partialSum(vt, cache);

	while (m--)
	{
		int a, b, sum = 0;
		scanf("%d %d", &a, &b);
		
		if (a > b)
			swap(a, b);

		if (a == b)
			printf("%d\n", vt[a - 1]);
		else
		{
			if(a == 1)
				printf("%d\n", cache[b - 1]);
			else 
				printf("%d\n", cache[b - 1] - cache[a - 2]);
		}
	}

	return 0;
}

