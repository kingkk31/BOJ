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

int solve(int n, int r, int c)
{
	if (n == 0)
		return 0;

	if (r < pow(2, n - 1))
	{
		if (c < pow(2, n - 1))
			return solve(n - 1, r, c); //1
		else
			return solve(n - 1, r, c - pow(2, n - 1)) + pow(2, 2 * (n - 1)); //2
	}
	else
	{
		if (c < pow(2, n - 1))
			return solve(n - 1, r - pow(2, n - 1), c) + (2 * pow(2, 2 * (n - 1))); //3
		else
			return solve(n - 1, r - pow(2, n - 1), c - pow(2, n - 1)) + (3 * pow(2, 2 * (n - 1))); //4
	}
}

int main(void)
{
	int n, r, c;
	while (~scanf("%d %d %d", &n, &r, &c))
		printf("%d\n", solve(n, r, c));
	return 0;
}
