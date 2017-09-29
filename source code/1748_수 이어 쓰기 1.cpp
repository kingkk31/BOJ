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

	unsigned long long len = 0;
	for (int i = 1; i <= n; i++)
	{
		if (0 <= i && i < 10)
			len += 1;
		else if (10 <= i && i < 100)
			len += 2;
		else if (100 <= i && i < 1000)
			len += 3;
		else if (1000 <= i && i < 10000)
			len += 4;
		else if (10000 <= i && i < 100000)
			len += 5;
		else if (100000 <= i && i < 1000000)
			len += 6;
		else if (1000000 <= i && i < 10000000)
			len += 7;
		else if (10000000 <= i && i < 100000000)
			len += 8;
		else if (100000000 <= i && i < 1000000000)
			len += 9;
		else if (1000000000 <= i && i < 10000000000)
			len += 10;
	}

	cout << len << endl;
}