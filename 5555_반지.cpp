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

int solve(string str, string temp)
{
	for (int i = 0; i < temp.length(); i++)
	{
		bool ch = false;
		int pos = i;
		for (int j = 0; j < str.length(); j++)
		{			
			if (temp[pos] != str[j])
			{
				ch = true;
				break;
			}
			pos = (pos + 1) % temp.length();
		}

		if (!ch)
			return 1;
		ch = false;
	}

	return 0;
}

int main(void)
{
	string str;
	int n, cnt = 0;
	cin >> str >> n;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		cnt += solve(str, temp);
	}

	cout << cnt << endl;

	return 0;
}