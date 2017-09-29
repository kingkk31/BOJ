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
	int n;
	scanf("%d", &n);
	vector<long long> vt(10001, 0);
	long long ans = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		vt[num]++;
	}

	for (int i = 0; i <= 10000; i++) 
	{
		if (vt[i] == 0)
			continue;

		for (int j = 0; j < i; j++) 
			if (vt[j] > 0)
				ans += i * j * vt[i] * vt[j];
		
		if (vt[i] > 1)
			ans += (i * i * vt[i] * (vt[i] - 1)) / 2;
	}
	printf("%lld\n", ans);

	return 0;
}