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
	long long total = 0LL;
	for (int i = 0; i < 3; i++)
	{
		long long num;
		cin >> num;
		total += num;
	}
	cout << total << endl;

	return 0;
}