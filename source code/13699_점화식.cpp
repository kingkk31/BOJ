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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

long long cache[36];

long long solve(int pos)
{
	if (pos == 0)
		return 1;

	long long &ret = cache[pos];
	if (ret != -1) return ret; ret = 0;

	for (int i = 0; i < pos; i++)
		ret += solve(i)*solve(pos - i - 1);
	
	return ret;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	printf("%lld\n", solve(n));
		
	return 0;
}