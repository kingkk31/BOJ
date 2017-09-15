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

int cache[1001][1001];
string a, b;

int lcs(void)
{
	memset(cache, 0, sizeof(cache));
	
	for (int i = 1; i <= a.length(); i++)
		for (int j = 1; j <= b.length(); j++)
			if (a[i - 1] == b[j - 1])
				cache[i][j] = cache[i - 1][j - 1] + 1;
			else
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
	
	return cache[a.length()][b.length()];
}

int main(void) 
{
	cin >> a >> b;
	cout << lcs() << endl;

	return 0;
}