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
#pragma warning(disable:4996)
using namespace std;

bool second_sort(const pair<string, int> &left, const pair<string, int> &right)
{
	return left.second < right.second;
}

int main(void)
{
	int n;
	cin >> n;

	while (n--)
	{
		int m;
		cin >> m;

		vector<pair<string,int> > vt;

		for (int i = 0; i < m; i++)
		{
			string str;
			int num;
			cin >> str >> num;

			vt.push_back(make_pair(str, num));
		}

		sort(vt.begin(), vt.end(), second_sort);
		cout << vt.back().first << endl;
	}

	return 0;
}