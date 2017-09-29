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
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, a, b, c, d;
		scanf("%d", &n);

		a = n / 25;
		n %= 25;
		b = n / 10;
		n %= 10;
		c = n / 5;
		n %= 5;
		d = n;
		
        printf("%d %d %d %d\n", a, b, c, d);
	}

	return 0;
}