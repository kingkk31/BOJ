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
int cache[102][102][102];
string a, b, c;

int lcs(void)
{
	memset(cache, 0, sizeof(cache));

	for (int i = 1; i <= a.length(); i++)
		for (int j = 1; j <= b.length(); j++)
			for (int k = 1; k <= c.length(); k++)
				if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
					cache[i][j][k] = cache[i - 1][j - 1][k - 1] + 1;
				else
					cache[i][j][k] = max(cache[i][j][k - 1], max(cache[i - 1][j][k], cache[i][j - 1][k]));

	return cache[a.length()][b.length()][c.length()];
}

int main(void)
{
	cin >> a >> b >> c;
	cout << lcs() << endl;

	return 0;
}