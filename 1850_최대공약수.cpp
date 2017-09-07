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
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	if (b == 0)
		return a;

	return gcd(b, a%b);
}

int main(void)
{
	unsigned long long a, b, c;
	cin >> a >> b;

	c = gcd(a, b);

	for (int i = 0; i < c; i++)
		cout << 1;

	cout << endl;

	return 0;
}
