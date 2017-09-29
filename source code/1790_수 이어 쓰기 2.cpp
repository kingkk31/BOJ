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
	int n,k;
	cin >> n >> k;

	unsigned long long len = 0;
	for (int i = 1; i <= n; i++)
	{
		int plus;

		if (0 <= i && i < 10)
			plus = 1;
		else if (10 <= i && i < 100)
			plus = 2;
		else if (100 <= i && i < 1000)
			plus = 3;
		else if (1000 <= i && i < 10000)
			plus = 4;
		else if (10000 <= i && i < 100000)
			plus = 5;
		else if (100000 <= i && i < 1000000)
			plus = 6;
		else if (1000000 <= i && i < 10000000)
			plus = 7;
		else if (10000000 <= i && i < 100000000)
			plus = 8;
		else if (100000000 <= i && i < 1000000000)
			plus = 9;
		else if (1000000000 <= i && i < 10000000000)
			plus = 10;
		
		if (len + plus >= k)
		{
			string str = to_string(i);
			cout << str[str.length()-1 - (len+plus - k)] << endl;

			return 0;
		}

		len += plus;
	}

	cout << -1 << endl;

	return 0;
}