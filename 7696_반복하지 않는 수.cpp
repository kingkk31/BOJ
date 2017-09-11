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
#pragma warning(disable:4996)
using namespace std;

vector<int> vt;

void solve()
{
	int cnt = 0, num = 0;
	while (cnt < 1000000)
	{
		num++;
		int temp = num;
		int cache = (1 << 10);
		bool ch = false;

		while (temp != 0)
		{
			int t = temp % 10;
			if (cache & (1 << t))
			{
				ch = true;
				break;
			}
			cache |= (1 << t);
			temp /= 10;
		}

		if (!ch)
		{
			cnt++;
			vt[cnt] = num;
		}		
	}
}

int main(void)
{
	vt = vector<int>(1000001);
	solve();
	int n;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		cout << vt[n] << endl;
	}

	return 0;
}