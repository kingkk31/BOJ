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
	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		cout << a / b << " " << a%b << " / " << b << endl;
	}

	return 0;
}