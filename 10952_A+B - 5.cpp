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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int a, b;
	while (1)
	{
		scanf("%d %d", &a, &b);

		if (a == 0 && b == 0)
			break;

		cout << a + b << endl;
	}

	return 0;
}