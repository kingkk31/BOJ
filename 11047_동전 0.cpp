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
	int n, k;
	cin >> n >> k;

	vector<int> vt;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		vt.push_back(num);
	}

	vector<int>::iterator itr = upper_bound(vt.begin(), vt.end(), k);
	itr--;

	while (itr != vt.begin())
	{
		while (k >= (*itr))
		{
			k -= (*itr);
			cnt++;
		}
		itr--;
	}

	if (k > 0)
		cnt += k;

	cout << cnt << endl;

	return 0;
}