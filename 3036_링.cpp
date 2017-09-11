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

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main(void)
{
	int n, a;
	cin >> n >> a;
	n--;
	while (n--)
	{
		int b, g;
		cin >> b;
		g = gcd(a, b);
		cout << a / g << "/" << b / g << endl;
	}
	
	return 0;
}