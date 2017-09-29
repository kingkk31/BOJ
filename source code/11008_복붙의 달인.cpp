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
	int n;
	cin >> n;

	while (n--)
	{
		string s, p;
		cin >> s >> p;

		int cnt = s.length(), i = 0;
		
		while(i < s.length() - p.length() + 1)
		{
			if (s[i] == p[0])
			{
				bool ch = false;
				for (int j = 0; j < p.length(); j++)
				{
					if (s[i + j] != p[j])
					{
						ch = true;
						break;
					}
				}
				if (!ch)
				{
					i += p.length();
					cnt -= p.length() - 1;
					continue;
				}
			}
			i++;
		}

		cout << cnt << endl;
	}

	return 0;
}