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

int cache[21][101][2];
string str, devil, angel;

int solve(int let, int pos, int flag)
{
	if (let >= str.length())
		return 1;
	
	int &ret = cache[let][pos][flag];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = pos; i < devil.length(); i++)
	{
		if (flag == 0)
		{
			if (str[let] == angel[i])
				ret += solve(let + 1, i + 1, 1);
		}
		else
		{
			if (str[let] == devil[i])
				ret += solve(let + 1, i + 1, 0);
		}
	}

	return ret;
}

int main(void)
{
	cin >> str >> devil >> angel;
	memset(cache, -1, sizeof(cache));
	cout << solve(0, 0, 0) + solve(0, 0, 1) << endl;
	
	return 0;
}