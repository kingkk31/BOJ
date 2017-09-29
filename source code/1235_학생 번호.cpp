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

	vector<string> vt(n);
	char buf;
	int len;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		vt[i] = str;
		buf = getchar();
	}

	len = vt[0].length();
	set<string> temp;
	vector<string> num(n,"");
	int cnt = 0;

	for (int j = 0; j < len; j++)
	{
		temp.clear();
		for (int i = 0; i < n; i++)
		{
			num[i] = num[i] + vt[i][j];
			temp.insert(num[i]);
		}

		cnt++;
		if (temp.size() == n)
			break;
	}
	cout << cnt << endl;
	
	return 0;
}