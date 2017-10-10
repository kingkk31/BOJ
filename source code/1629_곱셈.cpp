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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

unsigned long long solve(unsigned long long a, unsigned long long b, unsigned long long c)
{
	if (b == 0)
		return 1;
	if (b % 2 == 0)
	{
		unsigned long long temp = (solve(a%c, b / 2, c) % c);
		return ((temp % c) * (temp % c)) % c;
	}
	else
	{
		unsigned long long temp = (solve(a%c, (b-1) / 2, c) % c);
		return (a * (((temp % c) * (temp % c)) % c) % c);
	}
}

int main(void)
{
	unsigned long long a, b, c;
	scanf("%llu %llu %llu", &a, &b, &c);
	cout << solve(a, b, c) << endl;

	return 0;
}