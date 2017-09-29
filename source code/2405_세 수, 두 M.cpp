#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
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
	int n;
	scanf("%d", &n);

	vector<long long> vt(n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &vt[i]);
	
	sort(vt.begin(), vt.end());

	long long maxi = 0;
	
	vector<long long> three1(2),three2(2);

	for (int i = 1; i < n - 1; i++)
	{
		long long mid = vt[i] * 3;

		three1[0] = vt.front();
		three1[1] = vt[i + 1];

		three2[0] = vt[i-1];
		three2[1] = vt.back();
		
		long long sum1 = three1[0] + three1[1] + vt[i];
		long long sum2 = three2[0] + three2[1] + vt[i];
		long long check = max(llabs(sum1 - mid), llabs(sum2 - mid));
		maxi = max(maxi, check);
	}		

	printf("%lld\n", maxi);

	return 0;
}
