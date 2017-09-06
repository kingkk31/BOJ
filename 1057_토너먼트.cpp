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

int n, a, b, cnt;
bool ch;

vector<int> solve(vector<int> vt)
{
	cnt++;
	vector<int> vt2;
	for (int i = 0; i < vt.size(); i += 2)
	{
		if ((vt[i] == a && vt[i + 1] == b) || (vt[i] == b && vt[i + 1] == a))
		{
			cout << cnt << endl;
			ch = true;
			return vt2;
		}
		if (vt[i] == a || vt[i] == b)
			vt2.push_back(vt[i]);
		else if (i+1 < vt.size() &&(vt[i + 1] == a || vt[i + 1] == b))
			vt2.push_back(vt[i + 1]);
		else
			vt2.push_back(vt[i]);
	}
	if (vt.size() % 2 != 0)
		vt.push_back(vt.back());
	return vt2;
}

int main(void)
{
	cin >> n >> a >> b;
	ch = false;
	cnt = 0;
	vector<int> vt(n);
	for (int i = 0; i < n; i++)
		vt[i] = i + 1;

	while (true)
	{
		vector<int> vt2 = solve(vt);
		if (ch)
			return 0;
		if (vt2.size() == 1)
			break;

		vt = vt2;
	}

	cout << -1 << endl;

	return 0;
}