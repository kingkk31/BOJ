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
    int n, m, i;
	long long maxi = 0, temp = 0;
    scanf("%d %d", &n, &m);

	vector<int> vt(n);
	for (i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	for (i = 0; i < m; i++)
		temp += vt[i];

	for (; i < n; i++)
	{
		temp -= vt[i - m];
		temp += vt[i];
		maxi = max(maxi, temp);
	}

	printf("%lld\n", maxi);
 
	return 0;
}