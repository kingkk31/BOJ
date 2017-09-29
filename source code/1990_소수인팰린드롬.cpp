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
#include <cctype>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

string arr[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
vector<int> vt;

bool prime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return n > 1;
}

int string_to_int(string s)
{
	int num = 0;
	for (int i = 0; i < s.length(); i++)
		num += ((int)(s[s.length() - 1 - i] - '0')) * pow(10, i);
	return num;
}

void solve(string str)
{
	for (int i = 0; i < 10; i++)
	{
		string temp = arr[i] + str + arr[i];
		if (temp.length() > 8)
			continue;

		if (temp[0] != '0')
		{
			int num = string_to_int(temp);
			if (prime(num))
				vt.push_back(num);
		}

		solve(arr[i] + str + arr[i]);
	}
}

int main(void)
{
	vt.push_back(5);
	vt.push_back(7);
	vt.push_back(11);
	for (int i = 0; i < 10; i++)
		solve(arr[i]);
	sort(vt.begin(), vt.end());
	
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < vt.size(); i++)
		if (a <= vt[i] && vt[i] <= b)
			printf("%d\n", vt[i]);
	printf("-1\n");

	return 0;
}