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
int n, cache[31];

int solve(int w) 
{
	if (w <= 1) return 1;
	
	int &ret = cache[w];
	if (ret != -1) return ret;
	ret = 0;

	ret = (solve(w - 2) * 2) + solve(w - 1);
	return ret;
}

int main(void) 
{
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	
	int all = solve(n);
	int sub = all;
	if(n%2 == 0)
		sub -= solve(n / 2 + 1);
	else
		sub -= solve(n / 2);
	cout << all - sub / 2 << endl;
	
	return 0;
}