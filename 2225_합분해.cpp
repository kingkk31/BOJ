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

int n, k;
int cache[201][201];

int solve(int num, int cnt)
{
	if (num == n)
		return 1;

	if (cnt == 0)
		return 0;

	int &ret = cache[num][cnt];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = 0; i <= n; i++)
		if (i + num <= n)
			ret =  (ret + (solve(i + num, cnt - 1) % 1000000000)) % 1000000000;
		
	return ret % 1000000000;
}

int main(void)
{
	cin >> n >> k;
	memset(cache, -1, sizeof(cache));
	
	cout << solve(0, k) << endl;

	return 0;
}