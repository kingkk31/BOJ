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

int main(void)
{
	long long n, m, *arr, cnt = 0;
	scanf("%lld %lld", &n, &m);
	
	arr = (long long *)malloc(sizeof(long long) * n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	
	for (int i = 0; i < n; i++) 
	{
		long long temp = arr[i];

		if (temp == m)
			cnt++;
		for (int j = i + 1; j < n; j++)
		{
			temp += arr[j];
			if (temp == m)
				cnt++;
		}
	}
	printf("%lld\n", cnt);

	return 0;
}