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

int main(void)
{
	vector<string> vt;

	for (int i = 0; i < 4; i++)
	{
		string str;
		cin >> str;

		vt.push_back(str);
	}

	vector<pair<int, int> > arr(15);
	int cnt = 0, total = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (i == 3 && j == 3)
				continue;

			pair<int, int> pa = make_pair(i, j);
			arr[cnt++] = pa;
		}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (vt[i][j] == '.')
				continue;

			pair<int, int> com = arr[vt[i][j] - 'A'];
			int dist = abs(i - com.first) + abs(j - com.second);
			total += dist;
		}

	cout << total << endl;

	return 0;
}