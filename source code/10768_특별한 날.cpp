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
	int a, b;
	cin >> a >> b;

	if (a == 2 && b == 18)
		cout << "Special" << endl;
	else if (a < 2 || (a == 2 && b < 18))
		cout << "Before" << endl;
	else
		cout << "After" << endl;

	return 0;
}