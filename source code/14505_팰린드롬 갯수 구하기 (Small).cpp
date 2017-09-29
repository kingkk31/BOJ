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
int cache[39][39];
string str;

int solve(int s, int e)
{
	int &ret = cache[s][e];
	if (ret != -1) return ret;
	ret = 1;

	for (int i = s + 1; i < e; i++)
		for (int j = i; j < e; j++)
			if (str[i] == str[j])
				ret += solve(i, j);
	return ret;
}

int main(void)
{
	cin >> str;
	memset(cache, -1, sizeof(cache));
	
	int len = str.length(), ans = 0;
	for (int i = 0; i < len; i++)
		for (int j = i; j < len; j++)
			if (str[i] == str[j])
				ans += solve(i, j);
	cout << ans << endl;

	return 0;
}