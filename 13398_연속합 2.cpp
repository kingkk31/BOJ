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
	int n;
	scanf("%d", &n);

	long long a = -100000000, b = -100000000, c = 0;
	for (int i = 0; i < n; i++)
	{
		long long num;
		scanf("%lld", &num);

		c = max(a, c + num);
		a = max(a + num, num);
		b = max(a, max(b, c));
	}
	cout << b << endl;
	
	return 0;
}