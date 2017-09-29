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
#pragma warning(disable:4996)
using namespace std;

int cache[1001][1001];
string a, b;
vector<char> c;

bool isRange(int i, int j)
{
	if (0 <= i && i < a.length() && 0 <= j && j < b.length())
		return true;
	return false;
}

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

void solve(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	
	if (cache[i][j] > cache[i - 1][j - 1] && cache[i][j] > cache[i - 1][j] && cache[i][j] > cache[i][j - 1])
	{
		c.push_back(a[i - 1]);
		solve(i - 1, j - 1);
	}
	else if(cache[i][j] == cache[i - 1][j] && cache[i][j] > cache[i][j - 1])
		solve(i - 1, j);
	else
		solve(i, j - 1);
}

int main(void)
{
	cin >> a >> b;
	cout << lcs() << endl;
	solve(a.length(), b.length());
	for (int i = c.size() - 1; i >= 0; i--)
		printf("%c", c[i]);
	cout << endl;

	return 0;
}