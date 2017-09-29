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
	int n;
	cin >> n;

	vector<pair<int, int> > vt;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		vt.push_back(make_pair(i + 1, num));
	}

	reverse(vt.begin(), vt.end());

	vector<int> ret;
	ret.push_back(vt.front().first);

	for (int i = 1; i < vt.size(); i++)
	{
		int cnt = vt[i].second;

		if(cnt == ret.size())
			ret.push_back(vt[i].first);
		else if (cnt < ret.size())
			ret.insert(ret.begin()+cnt, vt[i].first);
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;

	return 0;
}