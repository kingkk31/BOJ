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

int cache[1001];

int solve(int n)
{
	int &ret = cache[n];

	if (ret != -1)
		return ret;

	if (n > 1)
		ret = !solve(n - 1);
	
	if (ret == 1)
		return ret;

	if (n > 3)
		ret = !solve(n - 3);

	if (ret == 1)
		return ret;

	if (n > 4)
		ret = !solve(n - 4);

	return ret;
}

int main(void)
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	
	cache[1] = 1;
	cache[2] = 0;
	cache[3] = 1;
	cache[4] = 1;
	
	int cnt = solve(n);

	if (cnt == 1)
		cout << "SK" << endl;
	else
		cout << "CY" << endl;

	return 0;
}
