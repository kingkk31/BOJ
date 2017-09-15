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
	int n, a = 1, b = 0;
	cin >> n;

	while (n--)
	{
		int ta = a, tb = b;
		b = ta + tb;
		a = tb;
	}
	cout << a << " " << b << endl;
	
	return 0;
}