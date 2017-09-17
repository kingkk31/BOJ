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
int cache[1009][1009];
char str[1009];

int solve(int s, int e)
{
	if (s == e) return 1;
	if (s > e) return 0;
	
	int &ret = cache[s][e];
	if (ret != -1) return ret;
	ret = 0;

	ret = ((solve(s + 1, e) % 10007) + (solve(s, e - 1) % 10007)) % 10007;
	ret = (ret - (solve(s + 1, e - 1) % 10007)) % 10007;
	if (str[s] == str[e])
		ret = (ret + (solve(s + 1, e - 1) % 10007) + 1) % 10007;
	
	return (ret + 10007) % 10007;
}

int main(void)
{
	scanf("%s", str);
	memset(cache, -1, sizeof(cache));
	
	int ans = solve(0, strlen(str) - 1) % 10007;
	printf("%d\n", ans);

	return 0;
}