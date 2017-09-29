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

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void)
{
	int n;
	cin >> n;
	
	while (n--)
	{
		unsigned long long a, b;
		cin >> a >> b;
		cout << (a*b) / gcd(a, b) << endl;
	}

	return 0;
}