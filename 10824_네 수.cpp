#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;

	a = a + b;
	c = c + d;

	unsigned long long x = 0, y = 0;

	for (int i = 0; i < a.length(); i++)
		x += (unsigned long long)(a[i]-'0') * pow((double)10, (a.length() - i - 1));
	
	for (int i = 0; i < c.length(); i++)
		y += (unsigned long long)(c[i]-'0') * pow((double)10, (c.length() - i - 1));

	cout << x + y << endl;
	
	return 0;
}