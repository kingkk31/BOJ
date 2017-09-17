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

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a%b);
}

void henry(int &a, int& b) 
{
	int ret = 0;

	while (1)
	{
		if ((double)a / (double)b >= 1.0 / (double)ret)
			break;
		ret++;
	}

	a = a*ret - b;
	b = b*ret;

	int gd = gcd(a, b);
	a /= gd;
	b /= gd;
}

int main(void)
{
	int a, b, n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
	
		while (a != 1)
			henry(a, b);
	
		cout << b << endl;
	}

	return 0;
}