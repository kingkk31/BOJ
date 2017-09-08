#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int sqrtn = int(sqrt((double)n));
	for (int i = 3; i <= sqrtn; i += 2)
		if (n%i == 0)
			return false;

	return true;
}

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);

	int total = 0;
	int mini;

	if (m > n)
		swap(m, n);

	bool ch = false;

	for (int i = m; i <= n; i++)
	{
		if (isPrime(i))
		{
			total += i;
			
			if (!ch)
			{
				ch = true;
				mini = i;
			}
		}
	}

	if (!ch)
		printf("-1\n");
	else
	{
		printf("%d\n", total);
		printf("%d\n", mini);
	}
	
	return 0;
}