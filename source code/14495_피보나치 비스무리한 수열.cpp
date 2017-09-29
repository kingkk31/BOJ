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
	int n;
	scanf("%d", &n);

	long long cache[117];
	cache[0] = 1; cache[1] = 1; cache[2] = 1; 
	for (int i = 3; i < 116; i++)
		cache[i] = cache[i - 1] + cache[i - 3];
	printf("%lld\n", cache[n - 1]);

	return 0;
}