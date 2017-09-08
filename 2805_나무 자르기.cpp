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

int n;
long long m;
long long tree[1000001];

long long solve(long long left, long long right)
{
	long long mid, temp, ans = 0;

	while (left <= right)
	{
		temp = 0;
		mid = (left + right) / 2;
		
		for (int i = 0; i < n; i++)
			if(mid < tree[i])
				temp += tree[i] - mid;

		if (temp < m)
			right = mid - 1;
		else
		{
			ans = max(ans, mid);
			left = mid + 1;
		}
	}

	return ans;
}

int main(void)
{
	scanf("%d %lld", &n, &m);
	long long highest = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &tree[i]);
		highest = max(highest, tree[i]);
	}

	printf("%lld\n", solve(0, highest));

	return 0;
}