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

void bigplus(int *vt1, int *vt2, int len1, int len2)
{
	int vt3[10002] = { 0 };

	int len = (len1 > len2) ? len1 : len2;

	for (int i = 0; i < len; i++)
	{
		int num = vt1[i] + vt2[i];
		vt3[i] += num;

		int temp = vt3[i] / 10;
		vt3[i] %= 10;
		vt3[i + 1] += temp;
	}

	if (vt3[len] != 0)
		cout << vt3[len];
	for (int i = len - 1; i >= 0; i--)
		cout << vt3[i];
	cout << endl;
}

int main(void)
{
	char str1[10002], str2[10002];
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1), len2 = strlen(str2);

	int vt1[10002] = { 0 }, vt2[10002] = { 0 };

	for (int i = len1 - 1; i >= 0; i--)
	{
		int num = (int)(str1[i] - '0');
		vt1[len1 - i - 1] = num;
	}

	for (int i = len2 - 1; i >= 0; i--)
	{
		int num = (int)(str2[i] - '0');
		vt2[len2 - i - 1] = num;
	}

	bigplus(vt1, vt2, len1, len2);

	return 0;
}
