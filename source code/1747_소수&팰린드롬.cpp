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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

string intToString(int n)
{
	stringstream s;
	s << n;
	return s.str();
}

bool prime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return n > 1;
}

bool palindrome(string num)
{
	for (int i = 0; i < num.length() / 2; i++)
		if (num[i] != num[num.length() - 1 - i])
			return false;
	return true;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = n; i <= 1000000000; i++)
		if (prime(i) && palindrome(intToString(i)))
		{
			printf("%d\n", i);
			break;
		}

	return 0;
}