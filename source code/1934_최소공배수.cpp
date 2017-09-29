#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <assert.h>
#pragma warning(disable:4996)
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return (a*b) / gcd(a, b);
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin >> a >> b;
		cout << lcm(a, b) << endl;
	}

	return 0;
}