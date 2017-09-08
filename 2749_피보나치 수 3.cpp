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

const int p = 100000 * 15;
int fibo[p] = { 0,1 };

int main(void)
{
	long long n;
	cin >> n;
	
	for (int i = 2; i < p; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= 1000000;
	}
	cout << fibo[n % p] << endl;
	
	return 0;
}