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

typedef struct medal {
	int number, gold, silver, bronze;
	
}medal;

bool comp(medal left, medal right)
{
	if (left.gold > right.gold)
		return true;
	else if (left.gold == right.gold && left.silver > right.silver)
		return true;
	else if (left.gold == right.gold && left.silver == right.silver && left.bronze > right.bronze)
		return true;
	else
		return false;
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<medal> vt(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i].number >> vt[i].gold >> vt[i].silver >> vt[i].bronze;
		
	sort(vt.begin(), vt.end(), comp);
	
	int cnt = 1, ac = 1;
	medal pos = vt[0];

	if (vt[0].number == k)
		cout << cnt << endl;
	else 
	{
		for (int i = 1; i < n; i++)
		{
			if (pos.gold != vt[i].gold || pos.silver != vt[i].silver || pos.bronze != vt[i].bronze)
			{
				cnt += ac;
				ac = 1;
				pos = vt[i];
			}
			else
				ac++;

			if (vt[i].number == k)
			{
				cout << cnt << endl;
				break;
			}
		}
	}

	return 0;
}