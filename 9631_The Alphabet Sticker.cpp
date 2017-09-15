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
	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		string str;
		cin >> str;

		vector<pair<int,int> > vt;
		bool ch = false;
		long long a, b;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '?')
			{
				if(i == (str.length() - 1))
				{
					if (!ch)
						vt.push_back(make_pair(i, i));
					else
						vt.push_back(make_pair(a, i));
				}
				else 
				{
					if (!ch)
					{
						a = i;
						ch = true;
					}
				}
			}
			else
			{
				if (ch)
				{
					b = i - 1;
					vt.push_back(make_pair(a, b));
					ch = false;
				}
			}
		}

		long long cnt = 1;
		for (int i = 0; i < vt.size(); i++)
		{
			if ((vt[i].first == 0) || (vt[i].second == (str.length() - 1))) {}
			else
			{
				if (str[vt[i].second + 1] != str[vt[i].first - 1])
				{
					cnt *= (vt[i].second - vt[i].first + 2);
					cnt %= 1000000007;
				}
			}
		}

		cout << cnt%1000000007 << endl;
	}
	
	return 0;
}