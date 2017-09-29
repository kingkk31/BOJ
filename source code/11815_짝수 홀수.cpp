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
	unsigned long long t;
	scanf("%llu", &t);
	while (t--)
	{
		unsigned long long n;
		scanf("%llu", &n);
		unsigned long long half = (unsigned long long)sqrtl(n);
		if (half * half == n)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}