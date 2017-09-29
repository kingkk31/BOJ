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
	int a, b, n, temp = 0;
	vector<int> vt;
	cin >> a >> b >> n;

	for (int i = n - 1; i >= 0; i--)
	{
		int num;
		cin >> num;
		temp += num * pow((double)a, i);
	}

	while (temp > 0)
	{
		vt.push_back(temp % b);
		temp /= b;
	}

	for (int i = vt.size() - 1; i >= 0; i--)
		cout << vt[i] << " ";

	return 0;
}