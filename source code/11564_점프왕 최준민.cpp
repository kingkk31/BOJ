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
	long long k, a, b, cnt = 0;
	cin >> k >> a >> b;

	if (a <= 0 && 0 <= b)
	{
		cnt++;
		cnt += (abs(b) / k);
		cnt += (abs(a) / k);
	}
	else
	{
		if (a < 0 && b < 0)
			swap(a, b);

		cnt += (abs(b) / k);
		cnt -= (abs(a) / k);
		if (abs(a) % k == 0)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}

