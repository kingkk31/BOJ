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

int n, total, need[10001];

int binarySearch(int maxi)
{
	int left = 0, right = maxi, mid, ans = 0;
	
	while (left <= right)
	{
		mid = (left + right) / 2;
		
		long long temp = 0;
		for (int i = 0; i < n; i++)
			if (mid < need[i])
				temp += mid;
			else
				temp += need[i];

		if (temp > total)
			right = mid - 1;
		else
		{
			left = mid + 1;
			ans = max(ans, mid);
		}
	}

	return ans;
}

int main(void)
{
	int maxi = 0;
	long long sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &need[i]);
		maxi = max(maxi, need[i]);
		sum += need[i];
	}
	scanf("%d", &total);

	if (sum > total)
		cout << binarySearch(maxi) << endl;
	else
		cout << maxi << endl;

	return 0;
}
