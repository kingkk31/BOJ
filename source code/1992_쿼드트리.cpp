#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int n;
vector<string> vt;

string minimize(int y, int x, int div)
{
	if (div == 0)
		return string(1,vt[y][x]);
		
	int ny1 = y, nx1 = x;
	int ny2 = y, nx2 = x + (div);
	int ny3 = y + (div), nx3 = x;
	int ny4 = y + (div), nx4 = x + (div);

	string str1 = minimize(ny1, nx1, div / 2);
	string str2 = minimize(ny2, nx2, div / 2);
	string str3 = minimize(ny3, nx3, div / 2);
	string str4 = minimize(ny4, nx4, div / 2);
	
	string ret = str1;
	ret += str2;
	ret += str3;
	ret += str4;

	if (ret == "1111")
		return "1";
	else if (ret == "0000")
		return "0";

	return "(" + ret + ")";
}

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vt.push_back(str);
	}

	cout << minimize(0, 0, n/2) << endl;

	return 0;
}