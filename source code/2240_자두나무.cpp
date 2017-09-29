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

int t;
int cache[1001][31];
vector<int> vt;

int solve(int pos, int tree, int w)
{
	if (pos >= t)
		return 0;
	
	int &ret = cache[pos][w];
	if (ret != -1)
		return ret;
	ret = 0;

	ret = max(ret, solve(pos + 1, tree, w) + (vt[pos] == tree));
	if(vt[pos] != tree && w > 0)
		ret = max(ret, solve(pos + 1, (tree == 1 ? 2 : 1), w - 1) + 1);
	
	return ret;
}

int main(void)
{
	int w;
	cin >> t >> w;
	vt = vector<int>(t);
	for (int i = 0; i < t; i++)
		cin >> vt[i];

	memset(cache, -1, sizeof(cache));
	cout << max(solve(0, 1, w), solve(0, 2, w - 1)) << endl;

	return 0;
}