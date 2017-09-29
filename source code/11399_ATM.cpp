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
	int n;
	cin >> n;

	vector<unsigned long long> vt(n);

	for (int i = 0; i < n; i++)
		cin >> vt[i];

	sort(vt.begin(), vt.end());

	unsigned long long total = 0, temp = 0;

	for (int i = 0; i < vt.size(); i++)
	{
		temp += vt[i];
		total += temp;
	}

	cout << total << endl;

	return 0;
}