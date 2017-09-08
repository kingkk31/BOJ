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
	int cnt = 0, y[5] = { 0 }, x[5] = { 0 }, cross1 = 0, cross2 = 0;
	vector<pair<int, int> > vt(26);
	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			int num;
			cin >> num;
			vt[num] = make_pair(i, j);
		}
	
	for (int i = 1; i <= 25; i++)
	{
			int num;
			cin >> num;

			int dy = vt[num].first, dx = vt[num].second;
			if(++y[dy] == 5)
				cnt++;
						
			if (++x[dx] == 5)
				cnt++;

			if (dy == dx)
			{
				cross1++;
				if (cross1 == 5)
					cnt++;
			}

			if (dy + dx == 4)
			{
				cross2++;
				if (cross2 == 5)
					cnt++;
			}

			if (cnt >= 3)
			{
				cout << i << endl;
				return 0;
			}
	}

	return 0;
}