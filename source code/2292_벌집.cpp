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
	int n, flag = 1, cnt = 0;
	cin >> n;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		cnt++;
		if (i == n)
		{
			cout << flag + 1 << endl;
			break;
		}

		if (flag * 6 <= cnt)
		{
			cnt = 0;
			flag++;
		}
	}	
	
	return 0;
}