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

int main(void)
{
	int k;
	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		int n, gap = -1;
		cin >> n;
		vector<int> vt(n);
		for (int j = 0; j < n; j++)
			cin >> vt[j];

		sort(vt.begin(), vt.end());
		for (int j = 1; j < n; j++)
			gap = max(gap, vt[j] - vt[j - 1]);

		cout << "Class " << i << endl;
		cout << "Max " << vt.back() << ", Min " << vt.front() << ", Largest gap " << gap << endl;
	}

	return 0;
}