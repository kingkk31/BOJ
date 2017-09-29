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
	string str1, str2;
	cin >> str1 >> str2;

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int num1[2] = { 0 }, num2[2] = { 0 };

	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == '5' || str1[i] == '6')
		{
			num1[0] += (5 * (pow((double)10, i)));
			num1[1] += (6 * (pow((double)10, i)));
		}
		else
		{
			num1[0] += ((int)(str1[i] - '0') * (pow((double)10, i)));
			num1[1] += ((int)(str1[i] - '0') * (pow((double)10, i)));
		}
	}

	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] == '5' || str2[i] == '6')
		{
			num2[0] += (5 * (pow((double)10, i)));
			num2[1] += (6 * (pow((double)10, i)));
		}
		else
		{
			num2[0] += ((int)(str2[i] - '0') * (pow((double)10, i)));
			num2[1] += ((int)(str2[i] - '0') * (pow((double)10, i)));
		}
	}

	cout << num1[0] + num2[0] << " " << num1[1] + num2[1] << endl;

	return 0;
}