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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int main(void)
{
	int n, b, c; 
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d %d", &b, &c);

	unsigned long long ans = n;
	for (int i = 0; i < n; i++)
		a[i] -= b;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= 0)
			continue;

		ans += a[i] / c;
		if (a[i] % c != 0)
			ans++;
	}

	printf("%llu\n", ans);

	return 0;
}