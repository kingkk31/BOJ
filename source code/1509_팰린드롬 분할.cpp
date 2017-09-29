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
int cache[2509], len;
string str;

bool palindrom(int s, int e)
{
	bool flag = true;
	for (int i = 0; i < (e - s + 1); i++)
		if (str[s + i] != str[e - i])
		{
			flag = false;
			break;
		}
	return flag;
}

int solve(int pos)
{
	if (pos >= len)
		return 0;

	int &ret = cache[pos];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = pos; i < len; i++)
	{
		if (palindrom(pos, i))
			ret = min(ret, solve(i + 1) + 1);
	}

	return ret;
}

int main(void)
{
	cin >> str;
	len = str.length();
	memset(cache, -1, sizeof(cache));
	cout << solve(0) << endl;

	return 0;
}