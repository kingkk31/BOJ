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

vector<vector<int> > vt;

int solve(int pos, int cut)
{
	if (pos == cut)
		return 0;

	if (vt[pos].empty())
		return 1;

	int cnt = 0;
	for (int i = 0; i < vt[pos].size(); i++)
		cnt += solve(vt[pos][i], cut);
	
	if (cnt == 0 && binary_search(vt[pos].begin(), vt[pos].end(), cut))
		cnt = 1;

	return cnt;
}

int main(void)
{
	int n, root, cut;
	cin >> n;
	
	vt = vector<vector<int> >(n);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num == -1)
			root = i;
		else
			vt[num].push_back(i);
	}

	cin >> cut;
	cout << solve(root, cut) << endl;

	return 0;
}