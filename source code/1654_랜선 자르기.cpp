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
long long n, k, m;
vector<long long> vt;

long long binarySearch()
{
	long long left = 0, right = m, mid, cnt, maxi = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		cnt = 0;

		for (int i = 0; i < k; i++)
			cnt += (vt[i] / mid);
		
		if (cnt < n)
			right = mid - 1;
		else
		{
			left = mid + 1;
			maxi = max(maxi, mid);
		}
	}

	return maxi;
}

int main(void)
{
	scanf("%lld %lld", &k, &n);
	vt = vector<long long>(k);
	scanf("%lld", &vt[0]);
	m = vt[0];

	for (int i = 1; i < k; i++)
	{
		scanf("%lld", &vt[i]);
		m = max(m, vt[i]);
	}

	cout << binarySearch() << endl;

	return 0;
}