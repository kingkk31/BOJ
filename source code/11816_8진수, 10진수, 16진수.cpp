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

int solve(string str)
{
	int num = 0;

	if (str[1] == 'x')
	{
		int pos = 0;
		for (int i = str.length() - 1; i >= 2; i--)
		{
			int temp;
			switch (str[i])
			{
			case 'a': temp = 10; break;
			case 'b': temp = 11; break;
			case 'c': temp = 12; break;
			case 'd': temp = 13; break;
			case 'e': temp = 14; break;
			case 'f': temp = 15; break;
			default: temp = (int)(str[i] - '0'); break;
			}

			temp *= pow((double)16, pos++);
			num += temp;
		}
	}//16진수
	else
	{
		int pos = 0;
		for (int i = str.length() - 1; i >= 1; i--)
		{
			int temp = (int)(str[i] - '0');
			temp *= pow((double)8, pos++);
			num += temp;
		}
	}//8진수

	return num;
}

int main(void)
{
	string str;
	cin >> str;

	if (str[0] != '0')
	{
		cout << str << endl;
		return 0;
	}//10진수

	cout << solve(str) << endl;

	return 0;
}