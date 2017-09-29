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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

long long n;

void solve(long long low, long long up, long long p)
{
	if (n < low || n > up)
		solve(low + (p > 0) * -2 * p, up + (p < 0) * -2 * p, p * -2);
	if (p < 0 ? n < low - p : n > up - p)
	{
		n -= p;
		printf("1");
	}
	else 
		printf("0");
}

int main(void)
{
	scanf("%lld", &n);
	solve(0, 1, 1);
	
	return 0;
}