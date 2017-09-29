#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int t;
int vt[301][2];
int score[301];

void solve(int n, int sum, int cnt)
{
	if (n >= t)
		return;

	if (vt[n][cnt] < sum)
		vt[n][cnt] = sum;
	else
		return;

	if (cnt == 1)
		solve(n + 2, sum + score[n + 2], 0);
	else
	{
		solve(n + 1, sum + score[n + 1], cnt + 1);
		solve(n + 2, sum + score[n + 2], 0);
	}
}

int main(void)
{
	cin >> t;
	
	for (int i = 0; i < t; i++)
		cin >> score[i];
	
	solve(0, score[0], 0);
	solve(1, score[1], 0);

	cout << max(vt[t - 1][0], vt[t - 1][1]) << endl;

	return 0;
}
