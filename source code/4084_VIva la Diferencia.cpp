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

int main(void)
{
	int a, b, c, d;
	while (true)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;

		int cnt = 0;
		while (!(a == b && b == c && c == d))
		{
			int ta = abs(a - b);
			int tb = abs(b - c);
			int tc = abs(c - d);
			int td = abs(d - a);
			
			a = ta;
			b = tb;
			c = tc;
			d = td;
			cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}