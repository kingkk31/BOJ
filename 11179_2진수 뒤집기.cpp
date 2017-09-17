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
	int n, num = 0, c = 0;
	cin >> n;

	vector<int> vt;
	while (n > 0)
	{
		vt.push_back(n % 2);
		n /= 2;
	}

	for (int i = vt.size() - 1; i >= 0; i--)
		num += (vt[i] * pow((double)2,c++));
	cout << num << endl;

	return 0;
}