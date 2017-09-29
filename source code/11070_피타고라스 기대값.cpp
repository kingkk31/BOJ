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
		int n, m;
		scanf("%d %d", &n, &m);

		vector<long long> plus(1001,0);
		vector<long long> minus(1001,0);
		
		for (int i = 0; i < m; i++)
		{
			int a, b, p, q;
			scanf("%d %d %d %d", &a, &b, &p, &q);

			plus[a] += p;
			minus[a] += q;
			plus[b] += q;
			minus[b] += p;
		}

		long long mini = 987654321321LL, maxi = 0;
	
		for (int i = 1; i <= n; i++)
		{
			long long total = 0;
			if(plus[i] || minus[i])
				total = 1000LL * (plus[i] * plus[i]) / ((plus[i] * plus[i]) + (minus[i] * minus[i]));

			mini = min(mini,total);
			maxi = max(maxi, total);
		}

		printf("%lld\n", maxi);
		printf("%lld\n", mini);
	}

	return 0;
}
