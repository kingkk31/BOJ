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

int solve(int left, int top, int len, vector<string> vt)
{
	if (len == 1)
		return 1;

	if (vt[top][left] == vt[top][left + len - 1] && vt[top][left] == vt[top + len - 1][left] &&
		vt[top][left] == vt[top + len - 1][left + len - 1])
		return len * len;
	else
		return solve(left, top, len - 1, vt);
}

int main(void)
{
	int n,m;
	cin >> n >> m;
	
	vector<string> vt(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];
	
	int maxi = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			maxi = max(maxi, solve(j, i, (n - i < m - j ? n - i : m - j), vt));
	
	cout << maxi << endl;

	return 0;
}