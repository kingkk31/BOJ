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

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, sum = 0;
		scanf("%d", &n);
		int* arr = new int[n];
		scanf("%d", &arr[0]);
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &arr[i]);
			for (int j = 0; j < i; j++)
				sum += gcd(arr[i], arr[j]);
		}
		printf("%d\n", sum);
	}

	return 0;
}