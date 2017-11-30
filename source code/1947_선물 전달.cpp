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
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int n;
long long cache[1000002];

long long solve(int pos)
{
	if (pos == 1)
		return 0;
	if (pos == 2)
		return 1;

	long long &ret = cache[pos];
	if (ret != -1) return ret; ret = 0;

	ret = ((pos - 1) * (solve(pos - 1) % 1000000000)) % 1000000000;
	ret = (ret + ((pos - 1) * (solve(pos - 2) % 1000000000)) % 1000000000) % 1000000000;
	
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	printf("%lld\n", solve(n) % 1000000000);
	
	return 0;
}