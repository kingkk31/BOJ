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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;

	int temp = b;
	if (p > c)
		temp += (p - c) * d;

	cout << (a*p < temp ? a*p : temp) << endl;

	return 0;
}