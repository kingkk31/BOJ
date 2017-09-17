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
	string str;
	cin >> str;

	vector<bool> P(14, false);
	vector<bool> K(14, false);
	vector<bool> H(14, false);
	vector<bool> T(14, false);

	int p = 13, k = 13, h = 13, t = 13;

	for (int i = 0; i < str.length()-2; i += 3)
	{
		int num = (int)(str[i + 1] - '0') * 10 + (int)(str[i + 2] - '0');
		switch (str[i])
		{
		case 'P':
			if (P[num] == true)
			{
				cout << "GRESKA" << endl;
				return 0;
			}
			else
			{
				P[num] = true;
				p--;
			}
				break;

		case 'K': 
			if (K[num] == true)
			{
				cout << "GRESKA" << endl;
				return 0;
			}
			else
			{
				K[num] = true;
				k--;
			}
			break;

		case 'H': 
			if (H[num] == true)
			{
				cout << "GRESKA" << endl;
				return 0;
			}
			else
			{
				H[num] = true;
				h--;
			}
			break;

		case 'T': 
			if (T[num] == true)
			{
				cout << "GRESKA" << endl;
				return 0;
			}
			else
			{
				T[num] = true;
				t--;
			}
			break;
		}
	}	

	printf("%d %d %d %d\n", p, k, h, t);

	return 0;
}