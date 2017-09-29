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
		int n;
		scanf("%d", &n);
		vector<int> parent(n + 1, -1);
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			parent[b] = a;
		}

		int a, b;
		scanf("%d %d", &a, &b);

		vector<int> ancestors;
		int p = a;
		ancestors.push_back(p);
		while (parent[p] != -1)
		{
			ancestors.push_back(parent[p]);
			p = parent[p];
		}
		sort(ancestors.begin(), ancestors.end());

		p = b;
		while (parent[p] != -1)
		{
			if (binary_search(ancestors.begin(), ancestors.end(), p))
				break;
			p = parent[p];
		}

		printf("%d\n", p);
	}

	return 0;
}