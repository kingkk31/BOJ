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

vector<int> vt;

void divide(int n) //분할정복
{
	int sqrtn = int(sqrt((double)n));
	int check = -1;

	for (int i = sqrtn; i > 1; i--)
	{
		if (n%i == 0)
		{
			check = i;
			break;
		}
	}

	if (check == -1)
	{
		vt.push_back(n);
		return;
	}
	
	divide(check);
	divide(n / check);
}

int main(void)
{
	while (1)
	{
		vt.clear();

		int n;
		cin >> n;

		if (n == 0)
			break;

		divide(n);

		vector<vector<int> > temp(2);

		sort(vt.begin(), vt.end());

		for (int i = 0; i < vt.size(); i++)
		{
			if (temp[0].empty() || temp[0].back() != vt[i])
			{
				temp[0].push_back(vt[i]);
				temp[1].push_back(1);
			}
			else
			{
				(temp[1].back())++;
			}
		}

		int cnt = 1;

		for (int i = 0; i < temp[0].size(); i++)
			cnt *= (pow((double)temp[0][i], temp[1][i]) - pow((double)temp[0][i], temp[1][i] - 1));

		cout << cnt << endl;
	}

	return 0;
}