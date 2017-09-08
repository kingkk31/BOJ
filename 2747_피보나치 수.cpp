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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	long long first = 0, second = 1, temp;

	if (n == 0)
		cout << 0 << endl;
	else if (n == 1)
		cout << 1 << endl;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			temp = first + second;
			first = second;
			second = temp;
		}
		cout << second << endl;
	}
	
	return 0;
}