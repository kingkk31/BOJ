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

int cache[5001];
int n;
string str;

int solve(int pos)
{	
	if (pos < n && str[pos] == '0')
		return 0;

	if (pos >= n - 1)
		return 1;

	int &ret = cache[pos];
	if (ret != -1)
		return ret;
	ret = 0;

	if (str[pos] == '1')
			ret = ((solve(pos + 1) % 1000000) + (solve(pos + 2) % 1000000)) % 1000000;
	else if (str[pos] == '2')
	{
		if(pos + 1 < n && str[pos + 1] != '7' && str[pos + 1] != '8' && str[pos + 1] != '9')
			ret = ((solve(pos + 1) % 1000000) + (solve(pos + 2) % 1000000)) % 1000000;
		else
			ret = ((solve(pos + 1) % 1000000)) % 1000000;
	}
	else
		ret = ((solve(pos + 1) % 1000000)) % 1000000;

	return ret;
}

int main(void)
{
	memset(cache, -1, sizeof(cache));
	cin >> str;
	n = str.length();
	cout << solve(0) << endl;

	return 0;
}