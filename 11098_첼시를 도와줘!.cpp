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

bool pairSort(const pair<int, string> &left, const pair<int, string> &right)
{
	return left.first < right.first;
}

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<pair<int, string> > vt(n);
		for (int i = 0; i < n; i++)
		{
			int pay;
			string name;
			cin >> pay >> name;
			vt[i] = make_pair(pay, name);
		}

		sort(vt.begin(), vt.end(), pairSort);
		cout << vt.back().second << endl;
	}

	return 0;
}