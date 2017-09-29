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

int n;
unsigned long long cache[10][1001];

unsigned long long solve(int num, int len)
{
	if (len == n-1)
		return 1;
	
	unsigned long long &ret = cache[num][len];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = num; i < 10; i++)
		ret = (ret + (solve(i, len + 1) % 10007))%10007;
	
	return ret % 10007;
}

int main(void)
{
	cin >> n;

	memset(cache, -1, sizeof(cache));
	
	unsigned long long total = 0;
	for (int i = 0; i < 10; i++)
	{
		total += solve(i, 0);
		total %= 10007;
	}

	cout << total << endl;

	return 0;
}