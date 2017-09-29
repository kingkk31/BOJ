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
#pragma warning(disable:4996)
using namespace std;

unsigned long long solve(unsigned long long left, unsigned long long right, vector<unsigned long long> &h)
{
	if (left == right)
		return h[left];

	unsigned long long mid = (left + right) / 2;
	unsigned long long ret = max(solve(left, mid, h), solve(mid + 1, right, h));

	unsigned long long lo = mid, hi = mid + 1;
	unsigned long long height = min(h[lo], h[hi]);

	ret = max(ret, height * 2);

	while (left < lo || hi < right)
	{
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
		{
			++hi;
			height = min(height, h[hi]);
		}
		else
		{
			--lo;
			height = min(height, h[lo]);
		}

		ret = max(ret, height * (hi - lo + 1));
	}

	return ret;
}

int main(void)
{
	unsigned long long N;
	
	while (true)
	{
		cin >> N;
		if (N == 0)
			return 0;

		vector<unsigned long long> h;

		for (int i = 0; i < N; i++)
		{
			unsigned long long num;
			cin >> num;
			h.push_back(num);
		}

		cout << solve(0, N - 1, h) << endl;
	}
	return 0;
}