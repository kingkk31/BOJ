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
int cache[4009][4009];

int lcs(string &a, string &b)
{
	int maxi = 0;
	memset(cache, 0, sizeof(cache));

	for (int i = 1; i <= a.length(); i++)
		for (int j = 1; j <= b.length(); j++)
		{
			if (a[i - 1] == b[j - 1])
				cache[i][j] = cache[i - 1][j - 1] + 1;
			maxi = max(maxi, cache[i][j]);
		}

	return maxi;
}

int main(void)
{
	string a, b;
	cin >> a >> b;
	cout << lcs(a, b) << endl;

	return 0;
}