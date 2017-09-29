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

#define INF 987654321
int cache[1800006];

int solve(int num)
{
	if (num <= 0)
		return 1;

	if (cache[num] != -1)
		return cache[num];

	cache[num] = 0;

	int i = 0, mini = INF;
	while (num >= i*(i + 1)*(i + 2)) { i++; }
	i--;

	for (int j = i; j >= 1; j--)
	{
		if (num >= j*(j + 1)*(j + 2))
			mini = min(mini, solve(num - (j*(j + 1)*(j + 2))));
	}
	cache[num] = mini + 1;
	
	return cache[num];
}

int main(void)
{
	int n, cnt = 0;
	cin >> n;
	n *= 6;
	memset(cache, -1, sizeof(cache));

	cnt = solve(n);
	cout << cnt - 1 << endl;

	return 0;
}