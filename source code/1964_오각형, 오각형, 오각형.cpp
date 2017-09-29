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

int main(void)
{
	int n;
	cin >> n;
	
	cout << (long long)((((3 * (long long)n + 5) * (long long)n) / 2 + 1) % 45678) << endl;

	return 0;
}